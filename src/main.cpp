/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2019 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

#include <iostream>
#include <chrono>
#include <thread>

#include "Adafruit_DotStar.h"
#include "UXDC_Halo.pb.h"
#include "ecalcomm.h"
#include <boost/signals2.hpp>

// this is just for testing, should be moved to file handling section later
extern "C" {
    #define STB_IMAGE_IMPLEMENTATION
    #include "stb_image.h"
}
#include <vector>

const unsigned int DEFAULT_LEDS = 196;//144;


// Loads as RGBA... even if file is only RGB
// Feel free to adjust this if you so please, by changing the 4 to a 0.
bool load_image(std::vector<unsigned char>& image, const std::string& filename, int& x, int&y)
{
    int n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 3);
    // std::cout << "Channels found: " << n << std::endl;
    if (data != nullptr)
    {
        image = std::vector<unsigned char>(data, data + x * y * 3);
    }
    stbi_image_free(data);
    return (data != nullptr);
}


int main(int argc, char **argv)
{
	// Init Halo
	Adafruit_DotStar strip(DEFAULT_LEDS, DOTSTAR_BGR);
	// Clear Halo 
	strip.begin();
	strip.show();

	// Halo Clear complete strip
	strip.Halo_ClearAll();

	// Starting eCAL 
	eCAL_UXDCHalo mECAL;
	mECAL.Init();
	mECAL.Start_eCAL();

	boost::signals2::connection c1 = mECAL.signal_setcolor.connect([&strip](int r, int g, int b, int br)
	{
		strip.setBrightness(br);
		strip.fill(strip.Color(r,g,b),0,DEFAULT_LEDS);
		strip.show();
	});
	boost::signals2::connection c2 = mECAL.signal_clear.connect([&strip]()
	{
		strip.Halo_ClearAll();
	});
	boost::signals2::connection c3 = mECAL.signal_fadein.connect([&strip](int r, int g, int b, int br, int delay)
	{
		strip.Halo_Strip_FadeIn(strip.Color(r,g,b), br, delay);
	});
	boost::signals2::connection c4 = mECAL.signal_fadeout.connect([&strip](int r, int g, int b, int delay)
	{
		strip.Halo_Strip_FadeOut(strip.Color(r,g,b),delay);
	});

	boost::signals2::connection con5 = mECAL.signal_playanimation.connect([&strip](unsigned char anim_number)
	{
		int width, height;
		std::string filename = "";
		std::vector<unsigned char> animation;
		
		if (anim_number == 1)
			filename = "196 Alicia Welcome.bmp";
		else if (anim_number == 2)
			filename = "196 Alicia_child left behind.bmp";
		else if (anim_number == 3)
			filename = "196 Alicia Exit.bmp";
		else if (anim_number == 4)
			filename = "196 Andrew Welcome.bmp";		
		else if (anim_number == 5)
			filename = "196 Andrew Bye.bmp";
		else		
			filename = "";
		
		if (filename != "")
		{

		bool success = load_image(animation, filename, width, height);
		if (!success)	
			std::cout << "Error loading image " << filename << std::endl;		
		else 
			strip.Halo_PlayAnimation(animation,height,width);
		}
		else
		{
			std::cout << "Error selecting animation file, wrong argument" << std::endl;
		}
	});	
	
	
	
	

// test section for animation file handling
	std::string file_alicia_child = "196 Alicia_child left behind.bmp";
    std::string file_alicia_bye = "196 Alicia Exit.bmp";
    std::string file_alicia_welcome = "196 Alicia Welcome.bmp";
    std::string file_andrew_bye = "196 Andrew Bye.bmp";
    std::string file_andrew_welcome = "196 Andrew Welcome.bmp";
	std::vector<unsigned char> animation_alicia_child;
	std::vector<unsigned char> animation_alicia_welcome;
	std::vector<unsigned char> animation_alicia_bye;
	std::vector<unsigned char> animation_andrew_welcome;
	std::vector<unsigned char> animation_andrew_bye;

/* 
	auto startzeit = std::chrono::steady_clock::now();
		strip.Halo_PlayAnimation(image,height,width);
	auto stopzeit = std::chrono::steady_clock::now();
	auto dauer = std::chrono::duration_cast<std::chrono::milliseconds>(stopzeit - startzeit).count();
	std::cout << "Elapsed time for 46 frames: " << dauer << "ms"<< std::endl;
	std::cout << "Elapsed time should be: " << (height*(1000/60)) << "ms\n"; //49
	std::cout << "Actual frametime: " << (dauer/height) << "ms\n";
	std::cout << "Estimated frametime: " << (1000/60) << "ms\n";
	std::cout << "actual fps: " << (1000/(dauer/height)) << "\n";
*/


  // enter main loop
	while(1)
	{
/*		
    int width, height;
 
    bool success = load_image(animation_alicia_welcome, file_alicia_welcome, width, height);
    if (!success)
    {
        std::cout << "Error loading image " << file_alicia_welcome << std::endl;;
        return 1;
    }		
	strip.Halo_PlayAnimation(animation_alicia_welcome,height,width);	
    std::this_thread::sleep_for(std::chrono::milliseconds(500));		


		
	success = load_image(animation_alicia_bye, file_alicia_bye, width, height);
    if (!success)
    {
        std::cout << "Error loading image " << file_alicia_bye << std::endl;;
        return 1;
    }		
	strip.Halo_PlayAnimation(animation_alicia_bye,height,width);	
    std::this_thread::sleep_for(std::chrono::milliseconds(500));				


		
	success = load_image(animation_alicia_child, file_alicia_child, width, height);
    if (!success)
    {
        std::cout << "Error loading image " << file_alicia_child << std::endl;;
        return 1;
    }		
	strip.Halo_PlayAnimation(animation_alicia_child,height,width);	
    std::this_thread::sleep_for(std::chrono::milliseconds(500));				
	

		
	success = load_image(animation_andrew_welcome, file_andrew_welcome, width, height);
    if (!success)
    {
        std::cout << "Error loading image " << file_andrew_welcome << std::endl;;
        return 1;
    }		
	strip.Halo_PlayAnimation(animation_andrew_welcome,height,width);	
    std::this_thread::sleep_for(std::chrono::milliseconds(500));		
		

		
	success = load_image(animation_andrew_bye, file_andrew_bye, width, height);
    if (!success)
    {
        std::cout << "Error loading image " << file_andrew_bye << std::endl;;
        return 1;
    }		
	strip.Halo_PlayAnimation(animation_andrew_bye,height,width);	
    std::this_thread::sleep_for(std::chrono::milliseconds(500));			
*/		
		
		
	//strip.fill(strip.Color(50,0,0),0,72);	
	//strip.show();
     //sleep 1000 ms
     

//
//	strip.fill(strip.Color(0,50,0),0,72);	
//	strip.show();
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//	strip.fill(strip.Color(0,0,50),0,72);	
//	strip.show();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

	}

  return(0);
}
