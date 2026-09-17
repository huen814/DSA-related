#include <stdio.h>
#include <string.h>
#include "cursorBase.h"

typedef int cbList;

void displayList(cbList C, VirtualHeap V)
{

    int current = C;

    while (current != -1)
    {
        printf("%c ", V.Nodes[current].data);
        current = V.Nodes[current].link;
    }
}

void insertLast(cbList *C, char X, VirtualHeap *V)
{

    int newNode = allocSpace(V);
    V->Nodes[newNode].data = X;
    V->Nodes[newNode].link = -1;

    if (*C == -1)
    {
        *C = newNode;
    }
    else
    {
        int current = *C;

        while (V->Nodes[current].link != -1)
        {
            current = V->Nodes[current].link;
        }
        V->Nodes[current].link = newNode;
    }
}

void deleteElem(cbList *C, char X, VirtualHeap *V)
{

    cbList previous = -1;
    cbList current = *C;

    while (current != -1 && V->Nodes[current].data != X)
    {
        previous = current;
        current = V->Nodes[current].link;
    }

    if (current == -1)
    {
        return;
    }

    if (previous == -1)
    {
        *C = V->Nodes[current].link;
    }
    else
    {
        V->Nodes[previous].link = V->Nodes[current].link;
    }

    deallocSpace(V, current);
}

int main()
{

    VirtualHeap H;
    initializeVHeap(&H);

    cbList L = -1;

    char elem[] = "BBACBBDB";
    int len = strlen(elem);
    for (int x = 0; x < len; x++)
    {
        insertLast(&L, elem[x], &H);
    }

    displayList(L, H);
    deleteElem(&L, 'B', &H);
    printf("\n");
    displayList(L, H);
}