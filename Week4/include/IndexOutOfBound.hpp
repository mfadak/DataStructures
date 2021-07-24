#ifndef INDEXOUTOFBOUND_HPP
#define INDEXOUTOFBOUND_HPP

#include "Exception.hpp"

class IndexOutOfBound : public Exception{
	public:
		IndexOutOfBound(const string &msg):Exception(msg) { }
};
#endif
