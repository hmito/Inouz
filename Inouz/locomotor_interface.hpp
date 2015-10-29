#ifndef INOUZ_MOVEMENTINTERFACE_INC
#define INOUZ_MOVEMENTINTERFACE_INC 100
#
#include"map.hpp"
namespace inouz{
	struct locomotor_interface{
		virtual void move(position Pos) = 0;
		virtual void operator()(void) = 0;
	};
}
#
#endif
