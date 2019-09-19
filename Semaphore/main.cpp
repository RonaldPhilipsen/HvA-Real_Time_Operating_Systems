#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void* thread1(void *)
{
	for (int i = 0; i < 5; ++i) {
		printf("sectie 1\n");
		sleep(1);
	}
	sem_post(&sem);
}

void* thread2(void *) {
	sem_wait(&sem);
	for (int i = 0; i < 5; ++i) {
		printf("sectie 2\n");
		sleep(1);
	}
}

void Opgave3a() {
	sem_init(&sem, 0, 0);

	// pthread meuk
	pthread_t tid1;
	pthread_attr_t tattr;

	pthread_attr_init(&tattr);
	pthread_attr_setschedpolicy(&tattr, SCHED_RR);

	pthread_create(&tid1, &tattr, thread1, 0);
	pthread_create(&tid1, &tattr, thread2, 0);

	pthread_join(tid1, 0);
}

int main()
{
	Opgave3a();
}
