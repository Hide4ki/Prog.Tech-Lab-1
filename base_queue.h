#pragma once

#include <iostream>
#include "elem.h"
#include "myException.h"

using namespace std;

class base_queue
{
	elem *tail;
	elem *head;
public:
	base_queue(void);
	virtual ~base_queue(void);
	elem *getHead(void)const;
	elem *getTail(void)const;
	void setHead(elem *newHead);
	void setTail(elem *newTail);
	base_queue *operator + (const base_queue *op2);
	base_queue *operator + (elem *op2);
	base_queue *operator = (const base_queue *op2);
	virtual int pop() = 0;
	virtual void push(elem *newElem) = 0;
	virtual base_queue *copy(void) = 0;
	friend ostream &operator<< (ostream &stream, const base_queue *myQueue);
};

#include "public_queue.h"
#include "protected_queue.h"
#include "private_queue.h"