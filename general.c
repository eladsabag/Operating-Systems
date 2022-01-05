/*
 * general.c
 *
 *  Created on: Apr 24, 2021
 *      Author: elad
 */

#include "general.h"

int doF321(int n1) {
	int n = n1;
	int k = 0;
	while (1) {
		if (n <= 1) {
			printf("Number of Itertions : %d\n", k);
			return k;
		}
		k += 1;
		if (n % 2 == 0)
			n = n / 2;
		else
			n = 3 * n + 1;
		printf("%d %d %d\n", n1, n, k);
	}
}

