#pragma once

#include "base_queue.h"

class public_queue:public base_queue
{
public:
	base_queue *copy(void) override;
	int calcul(void) override;
};

