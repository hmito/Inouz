#ifndef INOUZ_UTILITY_INC
#define INOUZ_UTILITY_INC 100
#
#include<hmLib/position.hpp>
namespace inouz{
	typedef unsigned char id_type;
	typedef hmLib::di_position<int> position;
	struct path{
		enum result{ safe, begin_wall, end_wall, with_wall };
		position From;
		position To;
		result Result;
	};
}
#
#endif
