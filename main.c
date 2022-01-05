/*
 * threads.c
 *
 *  Created on: Apr 18, 2021
 *      Author: elad
 */
#include "pipes.h"
#include "buffers.h"
#include "threads.h"
#include "forks.h"
#include "general.h"

// RUN EACH PROGRAM SEPERATLY.

int main(void) {
	int size = 10,i;
	int arr[] = { 17, 65, 34, 91, 92, 93, 33, 16, 22, 75 };
	// Pipes
	question1(arr,size);

	// Buffers
	//question2(arr,size);

	// Threads
	/*
	pthread_t t;
	int vector[size];
	int arg;
	void *k = NULL;
	for(i=0 ; i < size ; i++) {
		val = arr[i];
		pthread_create(&t, NULL, question3, &arg);
		sleep(2);
		pthread_join(t, &k);
		vector[i]=*(int*)k;
		printf("%d)Number of iterations=%d\n", (i+1),vector[i]);
	}
	sleep(2);
	printf("\n");
	for(i = 0 ; i < size ; i++) {
		printf("%d)Number of iterations=%d\n", (i+1),vector[i]);
	}
	*/

	// Forks
	/*
	question4(arr,size);
	sleep(2);
	printf("\nPrint of the vector:\n");
	for (i = 0; i < size; i++) {
		printf("%d)Number of Itertions : %d\n",(i+1), vector4[i]);
	}
	*/
}

