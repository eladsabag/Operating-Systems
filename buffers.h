/*
 * buffers.h
 *
 *  Created on: Apr 19, 2021
 *      Author: elad
 */

#ifndef BUFFERS_H_
#define BUFFERS_H_

#include "general.h"

int* buffer;
int j;

#define BUF_SIZE 46
#define BUF_N 7

#define IN_0 0
#define OUT_0 1
#define START_0 2

#define IN_1 23
#define OUT_1 24
#define START_1 25

void buffers(int* arr, int size);
void writeFather(int* n1, int* n, int* k);
void writeSon(int* n1, int* n, int* k);
void readFather(int* n1, int* n, int* k);
void readSon(int* n1, int* n, int* k);
#endif /* BUFFERS_H_ */
