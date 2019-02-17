#pragma once
#include <iostream>
#include "base_queue.h"

class public_queue:public base_queue
{
public:
	int pop(void) override;
	void push(elem *newElem) override;
	base_queue *copy(void) override;
	int calcul(void);
	friend ostream &operator<< (ostream &stream, const base_queue *myQueue);
};

