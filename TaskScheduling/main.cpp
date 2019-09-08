#include <cstdio>
#include <pthread.h>
#include <sched.h>
#include <thread>
#include <chrono>
#include "tasks.hpp"

void Task1A();
void Task1B();
void Task1C();


int main()
{
	//Task1A();
	//Task1B();
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
	pthread_create(&tid[0], &tattr, TaskOne, NULL);
	pthread_create(&tid[1], &tattr, TaskTwo, NULL);
	pthread_create(&tid[2], &tattr, TaskThree, NULL);
	pthread_create(&tid[3], &tattr, TaskFour, NULL);

	std::chrono::milliseconds timespan(10000); // wait 10 seconds to proof program works
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

	pthread_create(&tid[0], &tattr, TaskThree, NULL);
	pthread_create(&tid[1], &tattr, TaskFour, NULL);

	//Wait for Thread two and three to finish
	for (int i = 0; i < 2; i++)
		pthread_join(tid[i], NULL);

	ret = pthread_attr_setschedparam(&tattr, &param);
	pthread_create(&tid[2], &tattr, TaskOne, NULL);
	pthread_create(&tid[3], &tattr, TaskTwo, NULL);

	std::chrono::milliseconds timespan(10000); 
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

	pthread_t tid[2];

	pthread_create(&tid[0], NULL, Thread1, NULL);
	pthread_create(&tid[1], NULL, Thread2, NULL);

	std::chrono::milliseconds timespan(10000);
	std::this_thread::sleep_for(timespan);

	for (int i = 0; i < 2; i++)
		pthread_cancel(tid[i]);

	printf("Killed threads for task 1C\n\n");
}



