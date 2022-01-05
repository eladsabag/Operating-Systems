/*
 * threads.c
 *
 *  Created on: Apr 24, 2021
 *      Author: elad
 */

#include "threads.h"

void* threads(void* arg) {
	int *k = (int*)malloc(sizeof(int));
	*k = doF321(val);
	arg = k;
	return arg;
}


