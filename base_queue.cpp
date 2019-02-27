#include "base_queue.h"

base_queue::base_queue(void)
{
	tail = 0;
	head = 0;
}

base_queue::~base_queue(void)
{	
	elem *tmp = tail;
	elem *tmp2;
	if(tmp!=0)
	{
		while(tmp->getLink()!=0)
		{
			tmp2 = tmp->getLink();
			delete tmp;
			tmp = tmp2;
		}
		delete tmp;
	}
}

int base_queue::pop(void)
{
	if(tail == 0)
		throw myException("Queue is empty!!!");
	elem *tmpTail = tail;
	elem *tmpHead = head;
	head = head->getLink();
	if(tmpHead == tmpTail)
		setTail(NULL);
	elem tmp = *tmpHead;	
	delete tmpHead;
	return *tmp.getValue();
} 

base_queue *base_queue::operator + (elem *op2)
{
	if(tail != 0)
		tail->setLink(op2);
	else
		head = op2;
	tail = op2;
	return this;
}

elem *base_queue::getHead(void) const
{
	return head;
};

elem *base_queue::getTail(void) const
{
	return tail;
};

void  base_queue::setHead(elem *newHead)
{
	head = newHead;
};

void  base_queue::setTail(elem *newTail)
{
	tail = newTail;
};

base_queue *base_queue::operator = (const base_queue *op2)
{
	elem *tmp = op2->head;
	if(op2->tail == 0)
		throw myException("Queue is empty!!!");
	while(tmp!=0)
	{
		(*this)+ new elem(*tmp->getValue());
		tmp = tmp->getLink();
	}
	return this;
}

base_queue *base_queue::operator+(base_queue *op2)
{
	if(op2 == 0)
		throw myException("Copy queue, not initialization!!!");
	if(tail == 0 || op2->tail == 0)
		throw myException("One of the queues or both are empty!!!");
	tail->setLink(op2->head);
	tail = op2->tail;
	op2->tail = 0;
	op2->head = 0;
	return this;
}

