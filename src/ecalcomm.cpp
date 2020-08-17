#include "ecalcomm.h"

#include <ecal/ecal.h>
#include <ecal/msg/protobuf/publisher.h>
#include <ecal/msg/protobuf/subscriber.h>
#include <chrono>
#include <thread>

#include "IAA_HaloSteeringWheel.pb.h"
#include "UXDC_Halo.pb.h"

void eCAL_UXDCHalo::Init()
{
	eCAL::Initialize(0, 0, "IAA_Halo_SteeringWheel_Controller");
	eCAL::Process::SetState(proc_sev_healthy, proc_sev_level1, "I feel good !");

}

void eCAL_UXDCHalo::DeInit()
{
	// finalize eCAL API
	eCAL::Finalize();
}

void eCAL_UXDCHalo::OnSetStripColor(const char* _topic, const IAA::Halo::SteeringWheel::SetColor_Strip &_msg, const long long _time, const long long _clock, const long long _id)
{
//	std::cout << "Color" << std::endl;
//	std::cout << "Red: " <<_msg.red()<< std::endl;
//	std::cout << "Green: " <<_msg.green()<< std::endl;
//	std::cout << "Blue: " <<_msg.blue()<< std::endl;
//	std::cout << "GlobalBrightness: " <<_msg.globalbrightness()<< std::endl;
	signal_setcolor(_msg.red(),_msg.green(),_msg.blue(),_msg.globalbrightness());
}

void eCAL_UXDCHalo::OnClearStrip(const char* _topic, const IAA::Halo::SteeringWheel::Clear_Strip &_msg, const long long _time, const long long _clock, const long long _id)
{
//	std::cout << "Color" << std::endl;
//	std::cout << "Red: " <<_msg.red()<< std::endl;
//	std::cout << "Green: " <<_msg.green()<< std::endl;
//	std::cout << "Blue: " <<_msg.blue()<< std::endl;
//	std::cout << "GlobalBrightness: " <<_msg.globalbrightness()<< std::endl;
	signal_clear();
}

void eCAL_UXDCHalo::OnCmdFadeIn(const char* _topic, const IAA::Halo::SteeringWheel::Cmd_FadeIn &_msg, const long long _time, const long long _clock, const long long _id)
{
	signal_fadein(_msg.red(),_msg.green(),_msg.blue(),_msg.brightness(), _msg.delay());
}

void eCAL_UXDCHalo::OnCmdFadeOut(const char* _topic, const IAA::Halo::SteeringWheel::Cmd_FadeOut &_msg, const long long _time, const long long _clock, const long long _id)
{
	signal_fadeout(_msg.red(),_msg.green(),_msg.blue(),_msg.delay());
}

void eCAL_UXDCHalo::OnStateMachine(const char* _topic, const IAA::Halo::SteeringWheel::HALO_SteeringWheelCommand &_msg, const long long _time, const long long _clock, const long long _id)
{
	if (_msg.command() == IAA::Halo::SteeringWheel::HALO_SteeringWheelCommand_CommandList::HALO_SteeringWheelCommand_CommandList_FADE_IN)
	{
		//signal_fadein(_msg.red(),_msg.green(),_msg.blue(),_msg.brightness(), _msg.delay());
		signal_fadein(255,255,255,255,0);
	}
	if (_msg.command() == IAA::Halo::SteeringWheel::HALO_SteeringWheelCommand_CommandList::HALO_SteeringWheelCommand_CommandList_FADE_OUT)
	{
		//signal_fadeout(_msg.red(),_msg.green(),_msg.blue(),_msg.delay());
		signal_fadeout(255,255,255,0);
	}	
	if (_msg.command() == IAA::Halo::SteeringWheel::HALO_SteeringWheelCommand_CommandList::HALO_SteeringWheelCommand_CommandList_IDLE_OFF)
	{
		signal_clear();
	}
}

void eCAL_UXDCHalo::Start_eCAL()
{
	std::thread (&eCAL_UXDCHalo::ecal_runner, this).detach();
}

void eCAL_UXDCHalo::ecal_runner()
{

	eCAL::protobuf::CPublisher<IAA::Halo::SteeringWheel::HALO_SteeringWheel_Status> pub_Status("HALO_SteeringWheel_Status");
	//pub_Status.SetRefFrequency(1.0, 3.0);
	
	eCAL::protobuf::CSubscriber<IAA::Halo::SteeringWheel::SetColor_Strip> sub_SetColor("Halo_SW_SetColor");
	eCAL::protobuf::CSubscriber<IAA::Halo::SteeringWheel::Clear_Strip> sub_ClearStrip("Halo_SW_ClearStrip");
	eCAL::protobuf::CSubscriber<IAA::Halo::SteeringWheel::Cmd_FadeIn> sub_fadein("Halo_SW_FadeIn");
	eCAL::protobuf::CSubscriber<IAA::Halo::SteeringWheel::Cmd_FadeOut> sub_fadeout("Halo_SW_FadeOut");
	
	eCAL::protobuf::CSubscriber<IAA::Halo::SteeringWheel::HALO_SteeringWheelCommand> sub_statemachine("HALO_SteeringWheelCommand");

	
	auto cb_setcolor = std::bind(&eCAL_UXDCHalo::OnSetStripColor, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
	sub_SetColor.AddReceiveCallback(cb_setcolor);
	
	auto cb_clearstrip = std::bind(&eCAL_UXDCHalo::OnClearStrip, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
	sub_ClearStrip.AddReceiveCallback(cb_clearstrip);
	
	auto cb_fadein = std::bind(&eCAL_UXDCHalo::OnCmdFadeIn, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
	sub_fadein.AddReceiveCallback(cb_fadein);	

	auto cb_fadeout = std::bind(&eCAL_UXDCHalo::OnCmdFadeOut, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
	sub_fadeout.AddReceiveCallback(cb_fadeout);	

	auto cb_statemachine = std::bind(&eCAL_UXDCHalo::OnStateMachine, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
	sub_statemachine.AddReceiveCallback(cb_statemachine);	

	
	IAA::Halo::SteeringWheel::HALO_SteeringWheel_Status status;
	
	auto cnt = 0;
	while(eCAL::Ok())
	{
		status.set_alive_counter(++cnt);
		pub_Status.Send(status);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
