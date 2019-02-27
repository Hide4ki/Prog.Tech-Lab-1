#pragma once

#include "base_queue.h"

class protected_queue:protected base_queue
{
public:
	base_queue *copy(void) override;
	int calcul(void) override;
	static base_queue *get_ptr(void);
};

