#pragma once

#include <unistd.h>
#include <sys/msg.h>
#include <cstdio>
#include <mqueue.h>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <pthread.h>
#include <cstdlib>

#define QUEUE_NAME  "/test_queue"
#define MAX_SIZE    1024
#define MSG_STOP    "exit"


struct arg_struct {
	void* arg1;
};

int fd[2];


void* sender(void *);
void* reader(void *);
void* readerb(void*);
void* writerb(void*);

void* thread1(void* argu);
void* thread2(void* argu);
void *create_shared_memory(size_t size);