/*
 * pipes.c
 *
 *  Created on: Apr 18, 2021
 *      Author: elad
 */
#include "pipes.h"

void pipes(int* arr, int size) {
	int pipeFather[2], pipeSon[2], current = 0,in = 0, limit = 10,n1, n, k;
	if (pipe(pipeSon) == -1) { // check success of father's pipe
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipeFather) == -1) { // check success of son's pipe
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid_t cpid = fork();
	if (cpid == -1) { // check success of fork
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0) { // son process
		while (1) {
			read(pipeSon[0], &n1, sizeof(int));
			read(pipeSon[0], &n, sizeof(int));
			read(pipeSon[0], &k, sizeof(int));
			if (n % 2 == 0 && n > 0) {
				while (n % 2 == 0 && n != 1) {
					n /= 2;
					k++;
				}
				write(pipeFather[1], &n1, sizeof(int));
				write(pipeFather[1], &n, sizeof(int));
				write(pipeFather[1], &k, sizeof(int));

			} else {
				printf("exit son process");
				exit(EXIT_SUCCESS);
			}
		}
	} else { // father process
		while (1) {
			if (current >= size && in == 0) {
				write(pipeSon[1], 0, sizeof(int));
				write(pipeSon[1], 0, sizeof(int));
				write(pipeSon[1], 0, sizeof(int));
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
				write(pipeSon[1], &n1, sizeof(int));
				write(pipeSon[1], &n, sizeof(int));
				write(pipeSon[1], &k, sizeof(int));
			} else {
				read(pipeFather[0], &n1, sizeof(int));
				read(pipeFather[0], &n, sizeof(int));
				read(pipeFather[0], &k, sizeof(int));
				if (n == 1) {
					in--;
					printf("Sum after calculation: n1=%d n=%d k=%d\n", n1, n, k);
				} else {
					n = n * 3 + 1;
					k++;
					write(pipeSon[1], &n1, sizeof(int));
					write(pipeSon[1], &n, sizeof(int));
					write(pipeSon[1], &k, sizeof(int));
				}
			}
		}
	}
}


