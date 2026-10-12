#include<stdio.h>
#include<stdbool.h>

#define MAX 10
#define EMPTY '@'
#define DELETE '*'

typedef char Dictionary[MAX];

int hash(char elem){

    return (elem % MAX);
}

void initOpen(Dictionary D){

    for(int i = 0; i < MAX; i++){
        D[i] = EMPTY; 
    }
}

bool member(Dictionary D,char elem){

    int pos = hash(elem);

    printf("Checking...\n");

    for(int i = 0; i < MAX && D[pos] != elem && D[pos] != EMPTY; i++){
    pos = (pos + 1) % MAX;
    }

    if(D[pos] == elem){
        printf("Element %c has a duplicate!",elem);
    }

    return(D[pos]== elem) ? true : false;
}

int insert(Dictionary D,char elem){

    int pos = hash(elem);

    for(int i = 0; i < MAX; i++){
    if(D[pos] == EMPTY || D[pos] == DELETE){
        D[pos] = elem;
        return true;
    }
    else{
        pos = (pos + 1) % MAX;
    }
}
}

void print(Dictionary D){

    for(int i = 0; i < MAX;i++){
        if(D[i] != DELETE && D[i] != EMPTY){
        printf("%c ", D[i]);
        }
    }

    printf("\n");
}

int main(){

    Dictionary d;

    initOpen(d);
    insert(d,'a');
    insert(d,'b');
    insert(d,'c');
    insert(d,'f');
    insert(d,'f');
    print(d);

    member(d,'f');

    return 0;
}