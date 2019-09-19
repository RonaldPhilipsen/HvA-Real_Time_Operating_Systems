#include "threads.hpp"

void* reader(void* args) {
	mqd_t mq;
	ssize_t bytes_read;
	struct mq_attr attr;
	char buffer[MAX_SIZE + 1];

	/* initialize the queue attributes */
	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = MAX_SIZE;
	attr.mq_curmsgs = 0;

	/* create the message queue */
	mq = mq_open(QUEUE_NAME, O_CREAT | O_RDONLY | O_NONBLOCK, 0644, &attr);

	while (1) {

		memset(buffer, 0x00, sizeof(buffer));
		bytes_read = mq_receive(mq, buffer, MAX_SIZE, 0);
		if (bytes_read >= 0) {
			printf("SERVER: Received message: %s\n", buffer);
		}
		else {
			printf("SERVER: None \n");
		}

		fflush(stdout);
		sleep(1);
	}

	/* cleanup */
	mq_close(mq);
	mq_unlink(QUEUE_NAME);

	return 0;
}


void* sender(void* args) {

	mqd_t mq;
	char buffer[MAX_SIZE];

	/* open the mail queue */
	mq = mq_open(QUEUE_NAME, O_WRONLY);

	for (int i = 0; i < 50; ++i) {
		snprintf(buffer, sizeof(buffer), "MESSAGE %d", i);

		printf("CLIENT: Send integer... \n");
		mq_send(mq, buffer, MAX_SIZE, 0);

		fflush(stdout);
	}

	mq_close(mq);

	return 0;
}

void* readerb()
{
	while (1) {
		int i;
		int result;

		result = read(fd[0], &i, 1);
		if (result != 1) {
			perror("read");
			exit(3);
		}
		printf("| R: %d\n", i);
		sleep(1);
	}
}
void* writerb()
{
	int result;
	for (int i = 0; i < 50; ++i) {
		result = write(fd[1], &i, 1);
		if (result != 1) {
			perror("write");
			exit(2);
		}
		printf("W: %d ", i);
		sleep(1);
	}
}

void* thread1(arg_struct* argu) {
	struct arg_struct* args = argu;
	void* shmem = args->arg1;
	for (int i = 0; i < 50; ++i) {
		char message[10];
		sprintf(message, "%d", i);
		char* parent_message = message;
		memcpy(shmem, parent_message, sizeof(parent_message));
		printf("t1: %s ", shmem);
		sleep(1);
	}
}

void* thread2(arg_struct* argu) {
	struct arg_struct* args = argu;
	void* shmem = args->arg1;
	while (1) {
		printf("| t2: %s\n", shmem);
		sleep(1);
	}
}

void* create_shared_memory(size_t size) {
	int protection = PROT_READ | PROT_WRITE;
	int visibility = MAP_SHARED;
	return mmap(0, size, protection, visibility, 0, 0);
}
