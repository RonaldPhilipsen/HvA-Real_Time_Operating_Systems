#pragma once
#include "tasks.h"

void* taskOne(void*) {
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

void* taskTwo(void*) {
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

void* taskThree(void*) {
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 8; j++) {
			printf("taak 3 %i\n", j);
			for (int m = 0; m <= 1000; m++)
				for (int n = 0; n <= 10000; n++);
		}
	}

}

void* taskFour(void*) {
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 8; j++) {
			printf("taak 4 %i\n", j);
			for (int m = 0; m <= 1000; m++)
				for (int n = 0; n <= 10000; n++);
		}
	}
}





