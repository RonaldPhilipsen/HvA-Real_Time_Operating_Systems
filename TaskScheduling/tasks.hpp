#pragma once
#include <cstdio>
#include "periodic.hpp"


static int t1_count;
static int t2_count;

void* TaskOne(void*);
void* TaskTwo(void*);
void* TaskThree(void*);
void* TaskFour(void*);
void* Thread1(void*);
void* Thread2(void*);
