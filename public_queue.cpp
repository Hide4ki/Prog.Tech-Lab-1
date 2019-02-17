#include "base_queue.h"

int public_queue::pop(void)
{
	elem *tmpTail = getTail();
	elem *tmpHead = getHead();
	if(tmpTail == 0)
		throw myException("Queue is empty!!!");
	setHead(tmpHead->getLink());
	if(tmpHead == tmpTail)
		setTail(NULL);
	elem tmp = *tmpHead;	
	delete tmpHead;
	return *tmp.getValue();
}

base_queue *public_queue::copy(void)
{
	if(this->getTail()==0)
		throw myException("Original queue is empty!!!");
	base_queue *copyQueue = new public_queue;
	*copyQueue = this;
	return copyQueue;
}

int public_queue::calcul(void)
{
	elem *tmp = getHead();
	if(getTail() == NULL)
		throw myException("Queue is empty!!!");
	int cnt = 0;
	while(tmp->getLink() != NULL)
	{
		if((*tmp) < tmp->getLink())
			cnt++;
		tmp = tmp->getLink();
	}
	return cnt;
}
