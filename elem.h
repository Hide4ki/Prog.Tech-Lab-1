#pragma once
#include <iostream>

using std::ostream;

class elem
{
	int *value;
	elem *linkToNext;
public:
	elem(int x);
	elem(const elem &myElem);
	~elem(void);
	void setLink(elem *next);
	elem *getLink(void);
	int *getValue(void);
	bool operator<(const elem* op2);
	friend ostream &operator << (ostream &stream,const elem &myElem);
};

