// Schrijf een c-programma dat de 4 taken met de posix-api in round robin schedult. 
// Thread 1 en thread 2 bevatten een oneindige while-loop en thread 3 en 4 zijn 
// aflopend (geen oneindige while-loop).
// Schrijf nu een C-programma dat eerst thread 3 en thread 4 in round robin uitvoert en
// na het beeindigen van thread 3 en thread 4 de uitvoer vervolgt met round robin tussen 
// thread 1 en thread 2.

#include <cstdio>
#include <pthread.h>
#include <sched.h>

void* taskOne(void*);
void* taskTwo(void*);
void* taskThree(void*);
void* taskFour(void*);


int main()
{
	pthread_attr_t tattr;
	pthread_t tid[4];

	int ret;
	sched_param param;

	ret = pthread_attr_init(&tattr); //tattr init met defaultwaarden 
	ret = pthread_attr_getschedparam(&tattr, &param);

	pthread_create(&tid[0], &tattr, taskThree, NULL);
	pthread_create(&tid[1], &tattr, taskFour, NULL);

	//Wait for Thread two and three to finish
	for (int i = 0; i < 2; i++)
		pthread_join(tid[i], NULL);

	ret = pthread_attr_setschedparam(&tattr, &param);
	pthread_create(&tid[2], &tattr, taskOne, NULL);
	pthread_create(&tid[3], &tattr, taskTwo, NULL);

	while (1) {
	
	};
	//return 0;
}

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





