#pragma once

#include "base_queue.h"

class private_queue:private base_queue
{
public:
	base_queue *copy(void) override;
	int calcul(void) override;
	static base_queue *get_ptr(void);
};

