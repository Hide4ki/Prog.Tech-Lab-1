#pragma once

#include <iostream>

using std::ostream;

class myException
{
	const char *textEx;
public:
	myException(const char *a):textEx(a){};
	friend ostream &operator<< (ostream &stream, const myException &a);
};
