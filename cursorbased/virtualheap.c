#include<stdio.h>
#include<stdlib.h>

#define MAX 7

typedef struct{
    char data;
    int link;
}nodeType;

typedef struct{
    nodeType nodes[MAX];
    int avail;
}virtualHeap;

typedef int cbList;

void initVirtualHeap(virtualHeap *V);
int allocSpace(virtualHeap *V);
void deallocSpace(virtualHeap *V,int index);
void displayList(cbList C,virtualHeap V);
void insertLast(cbList *C,virtualHeap *V);
void deleteElem(cbList *C,virtualHeap *V);

void initVirtualHeap(virtualHeap *V){

    //initialize the virtual heap - 1;

    for(int i = 0; i < MAX - 1; i++){
        V->nodes[i].link = i + 1;
    }

    V->nodes[MAX - 1].link = -1; 
    V->avail = 0;
}

int allocSpace(virtualHeap *V){

    if(V->avail == -1){
        return -1;
    }

    int index = V->avail;
    V->avail = V->nodes[index].link;

    return index;
}

void deallocSpace(virtualHeap *V,int index){

    V->nodes[index].link = V->avail;
    V->avail = index;
}

void insertLast(cbList *C,virtualHeap *V){

    char x;

    cbList trav;
    cbList temp;
    temp = allocSpace(V);

    if(temp != -1){
        printf("Enter value to insert into list: ");
        scanf(" %c", &x);
        V->nodes[temp].data = x;
        V->nodes[temp].link = -1;
    }

    if(*C == -1){
        *C = temp;
        return;
    }
    else{
        for(trav = *C; V->nodes[trav].link != -1; trav=V->nodes[trav].link){}
    }

    V->nodes[trav].link = temp;
}

void deleteElem(cbList *C,virtualHeap *V){
    
    char target;
    cbList temp;
    cbList *p;

    printf("Enter character to remove: ");
    scanf(" %c",&target);
    for(p = C; *p != -1 && V->nodes[*p].data != target; p = &(V->nodes[*p].link)){}
    if(*p != -1){
        temp = *p;
        *p = V->nodes[temp].link;
        deallocSpace(V,temp);
    }
}

void displayList(cbList C,virtualHeap V){

    cbList trav;

    for(trav = C; trav != - 1; trav = V.nodes[trav].link){
        printf("%c", V.nodes[trav].data);
    }

    printf("\n");
}

int main(){

    virtualHeap main;
    cbList list = -1;

    initVirtualHeap(&main);
    allocSpace(&main);
    insertLast(&list,&main);
    insertLast(&list,&main);
    insertLast(&list,&main);
    displayList(list,main);
    deleteElem(&list,&main);
    displayList(list,main);
    
    return 0;
}