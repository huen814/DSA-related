#include <stdio.h>
#include "golem.h"

void initHeap(MaxHeap *H) { H->lastNdx = -1; }

int isEmpty(MaxHeap H) { return H.lastNdx == -1; }

int size(MaxHeap H) { return H.lastNdx + 1; }

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

/* Inserts x and bubbles it up. */
void insert(MaxHeap *H, int x) {
    int child, parent;
    if (H->lastNdx == MAX - 1) return;
    H->Elem[++H->lastNdx] = x;
    child = H->lastNdx;
    parent = (child - 1) / 2;
    while (child > 0 && H->Elem[child] > H->Elem[parent]) {
        swap(&H->Elem[child], &H->Elem[parent]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

/* Removes and returns the LARGEST value. Returns -1 if empty. */
int deleteMax(MaxHeap *H) {
    int max, ndx = 0, largest, left, right;
    if (isEmpty(*H)) return -1;
    max = H->Elem[0];
    H->Elem[0] = H->Elem[H->lastNdx--];
    while (1) {
        largest = ndx; left = 2 * ndx + 1; right = 2 * ndx + 2;
        if (left <= H->lastNdx && H->Elem[left] > H->Elem[largest]) largest = left;
        if (right <= H->lastNdx && H->Elem[right] > H->Elem[largest]) largest = right;
        if (largest == ndx) break;
        swap(&H->Elem[ndx], &H->Elem[largest]);
        ndx = largest;
    }
    return max;
}

/* Returns the largest value without removing it. Returns -1 if empty. */
int peekMax(MaxHeap H) { return isEmpty(H) ? -1 : H.Elem[0]; }
