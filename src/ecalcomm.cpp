#include "ecalcomm.h"

#include <ecal/ecal.h>
#include <ecal/msg/protobuf/publisher.h>
#include <ecal/msg/protobuf/subscriber.h>
#include <chrono>
#include <thread>

#include "UXDC_Halo.pb.h"

void eCAL_UXDCHalo::Init()
{
	eCAL::Initialize(0, 0, "UXDC_Halo_Controller");
	eCAL::Process::SetState(proc_sev_healthy, proc_sev_level1, "I feel good !");

}

void eCAL_UXDCHalo::DeInit()
{
	// finalize eCAL API
	eCAL::Finalize();
}

void eCAL_UXDCHalo::OnSetStripColor(const char* _topic, const UXDC::Halo::SetColor_Strip &_msg, const long long _time, const long long _clock, const long long _id)
{
	signal_setcolor(_msg.red(),_msg.green(),_msg.blue(),_msg.globalbrightness());
}

void eCAL_UXDCHalo::OnClearStrip(const char* _topic, const UXDC::Halo::Clear_Strip &_msg, const long long _time, const long long _clock, const long long _id)
{
	signal_clear();
}

void eCAL_UXDCHalo::OnCmdFadeIn(const char* _topic, const UXDC::Halo::Cmd_FadeIn &_msg, const long long _time, const long long _clock, const long long _id)
{
	signal_fadein(_msg.red(),_msg.green(),_msg.blue(),_msg.brightness(), _msg.delay());
}

void eCAL_UXDCHalo::OnCmdFadeOut(const char* _topic, const UXDC::Halo::Cmd_FadeOut &_msg, const long long _time, const long long _clock, const long long _id)
{
	signal_fadeout(_msg.red(),_msg.green(),_msg.blue(),_msg.delay());
}

void eCAL_UXDCHalo::OnStateMachine(const char* _topic, const UXDC::Halo::SetEvent &_msg, const long long _time, const long long _clock, const long long _id)
{
	if (_msg.sendevent() == UXDC::Halo::SetEvent_EventCommandList::SetEvent_EventCommandList_FADE_IN)
	{
		std::cout << "Event received, fixed Fade In" << std::endl;
		//signal_fadein(_msg.red(),_msg.green(),_msg.blue(),_msg.brightness(), _msg.delay());
		signal_fadein(255,255,255,255,0);
	}
	if (_msg.sendevent() == UXDC::Halo::SetEvent_EventCommandList::SetEvent_EventCommandList_FADE_OUT)
	{
		std::cout << "Event received, fixed Fade Out" << std::endl;
		//signal_fadeout(_msg.red(),_msg.green(),_msg.blue(),_msg.delay());
		signal_fadeout(255,255,255,0);
	}	
	if (_msg.sendevent() == UXDC::Halo::SetEvent_EventCommandList::SetEvent_EventCommandList_IDLE_OFF)
	{
		std::cout << "Event received, Idle Off Halo" << std::endl;
		signal_clear();
	}
	if (_msg.sendevent() == UXDC::Halo::SetEvent_EventCommandList::SetEvent_EventCommandList_ANIM_01)
	{
		std::cout << "Event received, Playing (fixed) Animation 01" << std::endl;
	}
	if (_msg.sendevent() == UXDC::Halo::SetEvent_EventCommandList::SetEvent_EventCommandList_ANIM_02)
	{
		std::cout << "Event received, Playing (fixed) Animation 02" << std::endl;
	}
	if (_msg.sendevent() == UXDC::Halo::SetEvent_EventCommandList::SetEvent_EventCommandList_ANIM_03)
	{
		std::cout << "Event received, Playing (fixed) Animation 03" << std::endl;
	}
	if (_msg.sendevent() == UXDC::Halo::SetEvent_EventCommandList::SetEvent_EventCommandList_ANIM_04)
	{
		std::cout << "Event received, Playing (fixed) Animation 04" << std::endl;
	}
	if (_msg.sendevent() == UXDC::Halo::SetEvent_EventCommandList::SetEvent_EventCommandList_ANIM_05)
	{
		std::cout << "Event received, Playing (fixed) Animation 05" << std::endl;
	}
}

void eCAL_UXDCHalo::Start_eCAL()
{
	std::thread (&eCAL_UXDCHalo::ecal_runner, this).detach();
}

void eCAL_UXDCHalo::ecal_runner()
{

	eCAL::protobuf::CPublisher<UXDC::Halo::HALO_Status> pub_Status("UXDC_Halo_Status");
	
	eCAL::protobuf::CSubscriber<UXDC::Halo::SetColor_Strip> sub_SetColor("UXDC_Halo_SetColor");
	eCAL::protobuf::CSubscriber<UXDC::Halo::Clear_Strip> sub_ClearStrip("UXDC_Halo_ClearStrip");
	eCAL::protobuf::CSubscriber<UXDC::Halo::Cmd_FadeIn> sub_fadein("UXDC_Halo_FadeIn");
	eCAL::protobuf::CSubscriber<UXDC::Halo::Cmd_FadeOut> sub_fadeout("UXDC_Halo_FadeOut");
	
	eCAL::protobuf::CSubscriber<UXDC::Halo::SetEvent> sub_statemachine("UXDC_Halo_TriggerEvent");

	
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

	
	UXDC::Halo::HALO_Status status;
	
	auto cnt = 0;
	while(eCAL::Ok())
	{
		status.set_alive_counter(++cnt);
		pub_Status.Send(status);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
