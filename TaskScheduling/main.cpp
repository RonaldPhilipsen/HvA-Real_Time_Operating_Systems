#include <cstdio>
#include <pthread.h>

void* taskOne(void*);
void* taskTwo(void*);
void* taskThree(void*);
void* taskFour(void*);


int main()
{
	pthread_t tid;
	pthread_attr_t tattr;
	pthread_attr_init(&tattr);  //tattr init met defaultwaarden 
	pthread_attr_setschedpolicy(&tattr, SCHED_RR); //sched policy aanpassen 
	pthread_create(&tid, &tattr, taskOne, NULL);
	pthread_create(&tid, &tattr, taskTwo, NULL);
	pthread_create(&tid, &tattr, taskThree, NULL);
	pthread_create(&tid, &tattr, taskFour, NULL);

	printf("hello from TaskScheduling!\n");

	while (1) {};
	//return 0;
}

void* taskOne(void *) {
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

void* taskTwo(void *) {
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

void* taskThree(void *) {
	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 1; j <= 8; j++) {
				printf("taak 3 %i\n", j);
				for (int m = 0; m <= 1000; m++)
					for (int n = 0; n <= 10000; n++);
			}
		}
	}
}

void* taskFour(void *) {
	while (1) {
		for (int i = 0; i < 5; i++) {
			for (int j = 1; j <= 8; j++) {
				printf("taak 4 %i\n", j);
				for (int m = 0; m <= 1000; m++)
					for (int n = 0; n <= 10000; n++);
			}
		}
	}
}





