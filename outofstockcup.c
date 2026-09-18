#include <stdio.h>

// Mission 3

#define MAX 10

typedef struct Qcup
{
    int elem[MAX];
    int front;
    int rear;
    int count;
} Queue;

typedef Queue *Qptr;

void enqueue(Qptr mainQ, int value)
{

    if (mainQ->count != MAX)
    {
        mainQ->elem[mainQ->rear] = value;
        mainQ->rear = (mainQ->rear + 1) % MAX;
        mainQ->count = mainQ->count + 1;
    }
}

int dequeue(Qptr mainq)
{

    int val = -1;

    if (mainq->count != 0)
    {
        val = mainq->elem[mainq->front];
        mainq->front = (mainq->front + 1) % MAX;
        mainq->count = mainq->count - 1;
    }

    return val;
}

Queue filterAndRemoveBySize(Qptr mainQ, int targetSize)
{
    Queue cancelQ;
    cancelQ.front = 0;
    cancelQ.rear = 0;
    cancelQ.count = 0;
    int original = mainQ->count;

    for (int i = 0; i < original; i++)
    {
        int val = dequeue(mainQ);
        if(val == targetSize){
            enqueue(&cancelQ,val);
        }
        else{
            enqueue(mainQ,val);
        }
    }

    return cancelQ;
}

void display(Qptr mainQ){

    for(int i = 0; i < mainQ->count;i++){
        printf("%d ", mainQ->elem[(mainQ->front + i) % MAX]); 
    }
    
    printf("\n");
}

int main()
{

    Queue q;
    q.front = 0;
    q.rear = 0;
    q.count = 0;
    int target = 2;

    printf("The Out of Stock Cup Purge!\n");
    printf("Entire tray of grande cups(target = 2) needs to be removed!\n");
    printf("Pending orders: ");
    enqueue(&q, 3);
    enqueue(&q, 2);
    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 8);
    enqueue(&q, 10);
    enqueue(&q, 2);
    enqueue(&q, 7);
    display(&q);
    printf("Dequeue: ");
    dequeue(&q);
    display(&q);

    Queue remove = filterAndRemoveBySize(&q, target);

    printf("Cancellation queue: ");
    display(&remove);
}
