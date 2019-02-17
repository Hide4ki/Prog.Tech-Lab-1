#include "elem.h"

elem::elem(const elem &myElem)
{
	value = new int(*myElem.value);
	linkToNext = myElem.linkToNext;
}

elem::~elem(void)
{
	delete value;
}

elem *elem::getLink(void)
{
	return linkToNext;
}

void elem::setLink(elem *next)
{
	linkToNext = next;
}

elem::elem(int x):value(new int(x))
{
	linkToNext = 0;
}

int *elem::getValue(void)
{
	return value;
};

bool elem::operator < (const elem* op2)
{
	return *value<*op2->value;
}
