#ifndef NOSUCHELEMENT_HPP
#define NOSUCHELEMENT_HPP

#include "Exception.hpp"

class NoSuchElement : public Exception{
	public:
		NoSuchElement(const string &msg):Exception(msg) { }
};
#endif
