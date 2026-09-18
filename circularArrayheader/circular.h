#ifndef circle_H
#define circle_H

#define MAX 8

int front;
int rear;
int queue[MAX];

int isFull(){
    
     return (rear + 1) % MAX == front;   
}

int isEmpty(){

    return front == rear; 
}

int enqueue(int x){

    if(isFull()){
    return 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    return 1;
}

int dequeue(int *out){

    if(isEmpty()){
    return 0;
    }
    front = (front + 1) % MAX;
    *out = queue[front];
    return 1;
}

int display(){
    
    if(isEmpty()){
        return 0;
    }
   int i = (front + 1) % MAX;
   while(1){
    printf("%d ", queue[i]);
    if(i == rear) break;
    i = (i + 1) % MAX;
   }

   printf("\n");
   return 1;
}

#endif