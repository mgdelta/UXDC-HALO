
#include <boost/signals2.hpp>

#include "UXDC_Halo.pb.h"

class eCAL_UXDCHalo
{
	public:
		void Init();
		void DeInit();
		void Start_eCAL();
		
		void OnCmdFadeIn(const char* _topic, const UXDC::Halo::Cmd_FadeIn &_msg, const long long _time, const long long _clock, const long long _id);
		void OnCmdFadeOut(const char* _topic, const UXDC::Halo::Cmd_FadeOut &_msg, const long long _time, const long long _clock, const long long _id);
		void OnSetStripLength(const char* _topic, const UXDC::Halo::SetLength_Strip &_msg, const long long _time, const long long _clock, const long long _id);
		void OnSetStripColor(const char* _topic, const UXDC::Halo::SetColor_Strip &_msg, const long long _time, const long long _clock, const long long _id);
		void OnClearStrip(const char* _topic, const UXDC::Halo::Clear_Strip &_msg, const long long _time, const long long _clock, const long long _id);
	  
  		void OnStateMachine(const char* _topic, const UXDC::Halo::SetEvent &_msg, const long long _time, const long long _clock, const long long _id);

	  
		boost::signals2::signal<void(int,int,int,int)> signal_setcolor;
		boost::signals2::signal<void(void)> signal_clear;
		boost::signals2::signal<void(int,int,int,int,int)> signal_fadein;
		boost::signals2::signal<void(int,int,int,int)> signal_fadeout;
	  
	private:  
		void ecal_runner();
};
