#include <stdio.h>

#define MAX 14

typedef struct
{
    int elem[MAX];
    int last;
} Heap;

void insertHeap(Heap *H, int elem)
{

    if (H->last < MAX - 1)
    {

        int child = ++H->last;
        H->elem[child] = elem;

        int parent = (child - 1) / 2;

        while (child > 0 && H->elem[parent] > H->elem[child])
        {
            int temp = H->elem[parent];
            H->elem[parent] = H->elem[child];
            H->elem[child] = temp;

            child = parent;
            parent = (child - 1) / 2;
        }
    }
}

void deleteHeap(Heap *H)
{

    if(H->last < 0){
        return;
    }

    H->elem[0] = H->elem[H->last];
    H->last--;

    int parent = 0;
    int left;
    int right;
    int small;

    while (2 * parent + 1 <= H->last)
    {
        left = 2 * parent + 1;
        right = 2 * parent + 2;
        small = left;
        if (right <= H->last && H->elem[right] < H->elem[left])
        {
            small = right;
        }
        if (H->elem[parent] > H->elem[small])
        {
            int temp = H->elem[parent];
            H->elem[parent] = H->elem[small];
            H->elem[small] = temp;
            parent = small;
        }
        else
        {
            break;
        }
    }
}

void print(Heap *H){

    for(int i = 0;i <= H->last;i++){
        printf("%d ",H->elem[i]);
    }

    printf("\n");
}

int main(){

    Heap h;
    h.last = -1; //empty 

    insertHeap(&h,2);
    insertHeap(&h,3);
    insertHeap(&h,2);
    insertHeap(&h,6);
    insertHeap(&h,4);
    insertHeap(&h,9);
    insertHeap(&h,10);
    insertHeap(&h,10);
    insertHeap(&h,18);
    insertHeap(&h,7);
    insertHeap(&h,5);
    insertHeap(&h,4);

    print(&h);

    deleteHeap(&h);

    print(&h);

    return 0;
}