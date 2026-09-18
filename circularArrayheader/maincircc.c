#include<Stdio.h>
#include "circular.h"

int main(){

    int value;

    for(int i = 1; i < 8; i++){
        if(enqueue(i)){
            printf("%d ",i);
        }
        else{
            printf("Queue full.\n");
        }
    }

    printf("\n");

    for(int i = 0; i < 2; i++){
        if(dequeue(&value)){}
        else{
            printf("Queue empty.");
        }
    }

    display(&value);

    return 0;
}