#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <pthread.h>
#include "threads.hpp"

#define SEMPERM 0600

int threadPids[2];



//Schrijf een C - programma dat 2 pthreads aanmaakt en dmv een(posix)message
//queue 50 integers overstuurt van thread 1 naar thread 2.
void Opgave2a()
{
	pthread_t client, server;

	printf("Start...\n");

	pthread_attr_t tattr;

	pthread_attr_init(&tattr);
	pthread_attr_setschedpolicy(&tattr, SCHED_RR);

	pthread_create(&server, &tattr, &reader, 0);
	pthread_create(&client, &tattr, &sender, 0);

	pthread_join(server, 0);
	pthread_join(client, 0);

	printf("Done...\n");

}
//Schrijf een C - programma dat 2 pthreads aanmaakt en dmv een (posix)pipe
// 50 integers overstuurt van thread 1 naar thread 2.
void Opgave2b()
{
	pthread_t tid1, tid2;
	int result;

	result = pipe(fd);
	if (result < 0) {
		perror("pipe ");
		exit(1);
	}

	pthread_create(&tid1, 0, &readerb, 0);
	pthread_create(&tid2, 0, &writerb, 0);

	pthread_join(tid1, 0);
	pthread_join(tid2, 0);
}

//Schrijf een C - programma dat 2 pthreads aanmaakt en dmv shared memory 50
//integers overstuurt van thread 1 naar thread 2*/

void Opgave2c()
{
	void* shmem = create_shared_memory(128);

	pthread_t client, server;

	struct arg_struct args;
	args.arg1 = &shmem;

	printf("Start...\n");

	pthread_create(&server, 0, &thread1, &args);
	pthread_create(&client, 0, &thread2, &args);

	pthread_join(server, 0);
	pthread_join(client, 0);
}


int main()
{
	Opgave2a();
	Opgave2b();
	Opgave2c();
}