#pragma once
#include <cstdio>
#include <stdio.h>
#include <signal.h>

static int t1_count;
static int t2_count;

void* TaskOne(void*);
void* TaskTwo(void*);
void* TaskThree(void*);
void* TaskFour(void*);

void Thread1(union sigval val);
void Thread2(union sigval val);
