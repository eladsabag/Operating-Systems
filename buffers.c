/*
 * buffers.c
 *
 *  Created on: Apr 18, 2021
 *      Author: elad
 */
#include "buffers.h"

void buffers(int *arr, int size) {
	int current = 0, in = 0, limit = 10, n1, n, k;

	buffer = mmap( NULL, BUF_SIZE * sizeof(int),
	PROT_READ | PROT_WRITE,
	MAP_SHARED | MAP_ANONYMOUS, 0, 0);

	//CHECK mmap success
	if (buffer == MAP_FAILED) {  //check Success
		printf("Mapping Failed\n");
		return;
	}

	pid_t cpid = fork();
	if (cpid == -1) { // check success of fork
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0) {
		while (1) {
			readSon(&n1, &n, &k);
			if (n % 2 == 0 && n > 0) {
				while (n % 2 == 0 && n != 1) {
					n /= 2;
					k++;
				}
				writeFather(&n1, &n, &k);
			} else {
				printf("exit son process");
				_exit(EXIT_SUCCESS);
			}
		}
	} else {
		while (1) {
			if (current >= size && in == 0) {
				int a = 0;
				int b = 0;
				int c = 0;
				writeSon(&a, &b, &c);
				wait(NULL);
				printf("exit father process");
				exit(EXIT_SUCCESS);
			}
			if (in < limit && current < size) {
				n1 = arr[current++];
				n = n1;
				k = 0;
				in++;
				if (n % 2 == 1) {
					n = n * 3 + 1;
					k++;
				}
				while (((buffer[IN_0] + 1) % BUF_N) == buffer[OUT_0]);
				writeSon(&n1, &n, &k);
			} else {
				readFather(&n1, &n, &k);
				if (n == 1) {
					in--;
					printf("Sum after calculation: n1=%d n=%d k=%d\n", n1, n,
							k);
				} else {
					n = n * 3 + 1;
					k++;
					while (((buffer[IN_0] + 1) % BUF_N) == buffer[OUT_0]);
					writeSon(&n1, &n, &k);
				}
			}
		}
	}
	//UnMapping
	int err = munmap(buffer, BUF_SIZE * sizeof(int));

	//CHECK UnMapping success
	if (err != 0) {
		printf("UnMapping Failed\n");
		return;
	}
}

void writeFather(int *n1, int *n, int *k) {
	while (((buffer[IN_1] + 1) % BUF_N) == buffer[OUT_1])
		;
	j = buffer[IN_1] * 3 + START_1;
	buffer[j] = *n1;
	buffer[j + 1] = *n;
	buffer[j + 2] = *k;
	buffer[IN_1] = (buffer[IN_1] + 1) % BUF_N;
}

void writeSon(int *n1, int *n, int *k) {
	//while (((buffer[IN_0] + 1) % BUF_N) == buffer[OUT_SON])
	//	;
	j = buffer[IN_0] * 3 + START_0;
	buffer[j] = *n1;
	buffer[j + 1] = *n;
	buffer[j + 2] = *k;
	buffer[IN_0] = (buffer[IN_0] + 1) % BUF_N;
}

void readFather(int *n1, int *n, int *k) {
	while (buffer[IN_1] == buffer[OUT_1])
		;
	j = buffer[OUT_1] * 3 + START_1;
	*n1 = buffer[j];
	*n = buffer[j + 1];
	*k = buffer[j + 2];
	buffer[OUT_1] = (buffer[OUT_1] + 1) % BUF_N;
}

void readSon(int *n1, int *n, int *k) {
	while (buffer[OUT_0] == buffer[IN_0])
		;
	j = buffer[OUT_0] * 3 + START_0;
	*n1 = buffer[j];
	*n = buffer[j + 1];
	*k = buffer[j + 2];
	buffer[OUT_0] = (buffer[OUT_0] + 1) % BUF_N;
}
