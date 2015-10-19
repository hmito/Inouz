#ifndef INOUZ_IOMESSAGE_INC
#define INOUZ_IOMESSAGE_INC 100
#
#include<string>
namespace inouz{
	typedef std::string message_type;
	struct imessage{
		virtual bool can_get() = 0;
		virtual message_type get() = 0;
	};
	struct omessage{
		virtual bool can_put() = 0;
		virtual void put(message_type Msg) = 0;
	};
	struct iomessage:public imessage,public omessage{};
}
#
#endif
