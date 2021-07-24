#ifndef EMPTYLIST_HPP
#define EMPTYLIST_HPP

#include "Exception.hpp"

class EmptyList : public Exception{
	public:
		EmptyList(const string &msg):Exception(msg) { }
};
#endif
