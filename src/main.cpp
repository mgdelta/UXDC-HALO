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
#include "IAA_HaloSteeringWheel.pb.h"
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
    std::cout << "Channels found: " << n << std::endl;
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
	eCAL_HaloSteeringWheel mECAL;
	mECAL.Init();
	mECAL.Start_eCAL();

	boost::signals2::connection c1 = mECAL.signal_setcolor.connect([&strip](int r, int g, int b, int br)
	{
		strip.setBrightness(br);
		strip.fill(strip.Color(r,g,b),0,144);
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

// test section for png handling
    std::string filename = "196 Alicia Welcome_mg.bmp";
    
    int width, height;
    std::vector<unsigned char> image;
    bool success = load_image(image, filename, width, height);
    if (!success)
    {
        std::cout << "Error loading image\n";
        return 1;
    }
    
    std::cout << "Image width = " << width << '\n';
    std::cout << "Image height = " << height << '\n';
    
    const size_t RGBA = 3;

    
    int x = 98;
    int y = 1;
    size_t index = RGBA * (y * width + x);
    std::cout << "RGBA pixel @ (x=3, y=4): " 
              << static_cast<int>(image[index + 0]) << " "
              << static_cast<int>(image[index + 1]) << " "
              << static_cast<int>(image[index + 2]) << " "
              << static_cast<int>(image[index + 3]) << '\n';
     /*         
    for (int i = 0; i<(4*width*height); i++)
    {
		std::cout << +image[index +i] << " ";
	}
*/
std::vector<unsigned char> &pxdata = image;


	strip.Halo_setStripColor();


  // enter main loop
	while(1)
	{
	//strip.fill(strip.Color(50,0,0),0,72);	
	//strip.show();
     //sleep 1000 ms
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//
//	strip.fill(strip.Color(0,50,0),0,72);	
//	strip.show();
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));
//	strip.fill(strip.Color(0,0,50),0,72);	
//	strip.show();
//    std::this_thread::sleep_for(std::chrono::milliseconds(500));

	}

  return(0);
}
