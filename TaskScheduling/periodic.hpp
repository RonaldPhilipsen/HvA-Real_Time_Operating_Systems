#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/timerfd.h>

struct periodic_info {
	int timer_fd;
	unsigned long long wakeups_missed;
};

int make_periodic(unsigned int period, struct periodic_info* info);
void wait_period(struct periodic_info* info);