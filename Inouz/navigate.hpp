#ifndef INOUZ_NAVIGATE_INC
#define INOUZ_NAVIGATE_INC 100
#
#include"map_interface.hpp"
namespace inouz{
	struct navigate_interface{
	public:
		virtual void insertAgent(id_type ID_);
		virtual void eraseAgent(id_type ID_);
		virtual void registPath(path Path_);
	};
}
#
#endif
