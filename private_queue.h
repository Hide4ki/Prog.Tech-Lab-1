#pragma once
#include "base_queue.h"
class private_queue:private base_queue
{
public:
	int pop(void) override;
	base_queue *copy(void) override;
	int calcul(void);
	elem *getHead(void)const{return base_queue::getHead();};
	elem *getTail(void)const{return base_queue::getTail();};
	base_queue *operator + (const base_queue *op2);
	base_queue *operator + (elem *op2);
	base_queue *operator = (const base_queue *op2);
	friend ostream &operator<< (ostream &stream, const private_queue *myQueue);
};

