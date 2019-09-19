#include <cstdio>
#include <csignal>
#include <ctime>
#include <pthread.h>
#include <sched.h>
#include <thread>
#include <chrono>
#include <unistd.h>
#include "tasks.hpp"


void Task1A();
void Task1B();
void Task1C();

const std::chrono::milliseconds timespan(10000);


int main()
{
	Task1A();
	Task1B();
	Task1C();

	while (1) {

	};
}

void Task1A() {
	printf("starting task 1A\n\n");

	pthread_t tid[4];
	pthread_attr_t tattr;
	pthread_attr_init(&tattr);  //tattr init met defaultwaarden 
	pthread_attr_setschedpolicy(&tattr, SCHED_RR); //sched policy aanpassen 
	pthread_create(&tid[0], &tattr, TaskOne, 0);
	pthread_create(&tid[1], &tattr, TaskTwo, 0);
	pthread_create(&tid[2], &tattr, TaskThree, 0);
	pthread_create(&tid[3], &tattr, TaskFour, 0);

	std::this_thread::sleep_for(timespan);
	for (int i = 0; i < 4; i++)
		pthread_cancel(tid[i]);
	printf("Killed threads for task 1a\n\n");

}

// Schrijf een c-programma dat de 4 taken met de posix-api in round robin schedult. 
// Thread 1 en thread 2 bevatten een oneindige while-loop en thread 3 en 4 zijn 
// aflopend (geen oneindige while-loop).
// Schrijf nu een C-programma dat eerst thread 3 en thread 4 in round robin uitvoert en
// na het beeindigen van thread 3 en thread 4 de uitvoer vervolgt met round robin tussen 
// thread 1 en thread 2.
void Task1B() {
	printf("starting task 1B\n\n");

	pthread_attr_t tattr;
	pthread_t tid[4];

	int ret;
	sched_param param;

	ret = pthread_attr_init(&tattr); //tattr init met defaultwaarden 
	ret = pthread_attr_getschedparam(&tattr, &param);

	pthread_create(&tid[0], &tattr, TaskThree, 0);
	pthread_create(&tid[1], &tattr, TaskFour, 0);

	//Wait for Thread two and three to finish
	for (int i = 0; i < 2; i++)
		pthread_join(tid[i], 0);

	pthread_create(&tid[2], &tattr, TaskOne, 0);
	pthread_create(&tid[3], &tattr, TaskTwo, 0);

	std::this_thread::sleep_for(timespan);

	// Cancel all the running threads
	for (int i = 0; i < 4; i++)
		pthread_cancel(tid[i]);

	printf("Killed threads for task 1b\n\n");
}


// Schrijf een C-programma dat twee periodieke pthreads aanmaakt. 
// Thread1 heeft een periodetijd van 0,5 sek en thread 2 
// heeft een periodetijd van 1,3 sek. Iedere thread drukt per 
// periode de threadnaam en periodenummer af
void Task1C() {
	printf("starting task 1C\n\n");

	int Ret = 0;
	pthread_t tid[2];
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	struct sigevent sig;
	sig.sigev_notify = SIGEV_THREAD;
	sig.sigev_notify_function = Thread1;
	sig.sigev_value.sival_int = 1500;
	sig.sigev_notify_attributes = &attr;

	struct sigevent sig2;
	sig2.sigev_notify = SIGEV_THREAD;
	sig2.sigev_notify_function = Thread2;
	sig2.sigev_value.sival_int = 600;
	sig2.sigev_notify_attributes = &attr;
	
	timer_t timerid;
	timer_t timerid2;

	timer_create(CLOCK_REALTIME, &sig, &timerid);
	timer_create(CLOCK_REALTIME, &sig2, &timerid2);
	
	std::chrono::milliseconds timespan(10000);
	std::this_thread::sleep_for(timespan);

	for (int i = 0; i < 2; i++)
		pthread_cancel(tid[i]);

	printf("Killed threads for task 1C\n\n");
}





