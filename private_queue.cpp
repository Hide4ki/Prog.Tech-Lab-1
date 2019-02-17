#include "private_queue.h"
#include "base_queue.h"

private_queue::private_queue(void):base_queue()
{
}

private_queue::~private_queue(void)
{
	
}

int private_queue::pop(void)
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

void private_queue::push(elem *newElem)
{
	if(getTail() != 0)
		getTail()->setLink(newElem);
	else
		setHead(newElem);
	setTail(newElem);
}

base_queue *private_queue::copy(void)
{
	if(this->getTail()==0)
		throw myException("Original queue is empty!!!");
	base_queue *copyQueue = new private_queue;
	*copyQueue = this;
	return copyQueue;
}

int private_queue::calcul(void)
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

base_queue *private_queue::operator + (elem *op2)
{
	return *((base_queue*)this)+op2;
}


base_queue *private_queue::operator+(const base_queue *op2)
{
	return *((base_queue*)this)+op2;
}
