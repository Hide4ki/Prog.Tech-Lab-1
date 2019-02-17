#pragma once
#include <iostream>
#include "base_queue.h"

using namespace std;
enum A {PUBLIC, PROTECTED, PRIVATE};
void help(void);
void push(void);
void pop(void);
void show(void);
void calcul(void);
base_queue *copy(void);
void merge(base_queue *secondQ);
void setAccess(void);