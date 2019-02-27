#include "private_queue.h"
#include "base_queue.h"

base_queue *private_queue::get_ptr() 
{
	base_queue *result = new private_queue;
	return result;
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
	if(getTail() == NULL)
		throw myException("Queue is empty!!!");
	elem *tmp = getHead();
	int cnt = 0;
	while(tmp->getLink() != NULL)
	{
		if((*tmp) < tmp->getLink())
			cnt++;
		tmp = tmp->getLink();
	}
	return cnt;
}