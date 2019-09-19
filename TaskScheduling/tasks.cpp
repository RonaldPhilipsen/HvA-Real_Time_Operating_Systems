#pragma once
#include "tasks.hpp"

void* TaskOne(void*) {
	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 1; j <= 8; j++) {
				printf("taak 1 %i\n", j);
				for (int m = 0; m <= 1000; m++)
					for (int n = 0; n <= 10000; n++);
			}
		}
	}
}

void* TaskTwo(void*) {
	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 1; j <= 8; j++) {
				printf("taak 2 %i\n", j);
				for (int m = 0; m <= 1000; m++)
					for (int n = 0; n <= 10000; n++);
			}
		}
	}
}

void* TaskThree(void*) {
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 8; j++) {
			printf("taak 3 %i\n", j);
			for (int m = 0; m <= 1000; m++)
				for (int n = 0; n <= 10000; n++);
		}
	}
}

void* TaskFour(void*) {
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 8; j++) {
			printf("taak 4 %i\n", j);
			for (int m = 0; m <= 1000; m++)
				for (int n = 0; n <= 10000; n++);
		}
	}
}



void Thread1(union sigval val)
{
	printf("Thread 1 period 500ms\n");
}

void Thread2(union sigval val)
{
	printf("Thread 2 period 1300ms\n");
}
