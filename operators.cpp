#include <iostream>
#include "base_queue.h"

using namespace std;

ostream &operator<< (ostream &stream, const base_queue *myQueue)
{
	elem *tmp;
	if(myQueue == NULL)
		throw myException("No queue to show!!!");
	tmp = myQueue->head;
	if(myQueue->tail==NULL)
		throw myException("Queue is empty!!!");
	
	stream << "first << last" << endl;
	while(tmp!=NULL)
	{
		stream << *tmp;
		tmp = tmp->getLink();
	}
	return stream;
}

ostream &operator << (ostream &stream, const elem &myElem)
{
	stream << *myElem.value;
	if(myElem.linkToNext != 0)
		stream << " << ";
	else
		stream << endl;
	return stream;
}

ostream &operator<< (ostream &stream, const myException &a)
{
	stream  << "Error!!! " << a.textEx << endl;
	return stream;
}