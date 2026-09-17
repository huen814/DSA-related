#ifndef Cursor_H
#define Cursor_H

#define MAX 9

typedef struct
{
    char data;
    int link;
} nodetype;

typedef struct
{
    nodetype Nodes[MAX];
    int available;
} VirtualHeap;

void initializeVHeap(VirtualHeap *VH)
{

    int i;

    for (int i = 0; i < MAX - 1; i++)
    {
        VH->Nodes[i].link = i + 1;
    }

    VH->Nodes[MAX - 1].link = 0;

    VH->available = 1;
}

int allocSpace(VirtualHeap *VH)
{

    int newdata = VH->available;
    VH->available = VH->Nodes[newdata].link;

    return newdata;
}

void deallocSpace(VirtualHeap *VH, int N)
{

    VH->Nodes[N].link = VH->available;
    VH->available = N;
}

#endif