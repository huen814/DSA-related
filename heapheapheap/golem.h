#ifndef GOLEM_H
#define GOLEM_H

#include <stdio.h>

#define MAX 100

typedef struct {
    int Elem[MAX];
    int lastNdx;            /* index of last element, -1 if empty */
} MaxHeap;

void initHeap(MaxHeap *H);

int isEmpty(MaxHeap H);

int size(MaxHeap H);

void swap(int *a, int *b);

/* Inserts x and bubbles it up. */
void insert(MaxHeap *H, int x);

/* Removes and returns the LARGEST value. Returns -1 if empty. */
int deleteMax(MaxHeap *H);

/* Returns the largest value without removing it. Returns -1 if empty. */
int peekMax(MaxHeap H);

/* ---------- FUNCTION YOU WILL WRITE ---------- */
int lastGolem(MaxHeap *H);

#endif
