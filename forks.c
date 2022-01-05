/*
 * forks.c
 *
 *  Created on: Apr 24, 2021
 *      Author: elad
 */

#include "forks.h"

void forks(int *arr, int size) {
	int n1, n, k, i, counter = 0, current;
	vector4 =(int*)malloc(sizeof(int)*size);
	pid_t cpid;
	for (i = 0; i < size; i++) {
		cpid = fork();
		if (cpid == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		}
		current = counter++;
		n1 = arr[current];
		n = n1;
		k = 0;
		if (cpid == 0) {
			while (n != 1) {
				k += 1;
				if (n % 2 == 0)
					n = n / 2;
				else
					n = 3 * n + 1;
				printf("%d %d %d\n", n1, n, k);
			}
			vector4[current] = k;
			sleep(1);
			printf("%dst number arrived with %d iterations\n",(i+1),vector4[current]);
			sleep(1);
		}
		else {
			exit(EXIT_SUCCESS);
		}
	}
}

