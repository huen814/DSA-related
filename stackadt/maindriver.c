#include <stdio.h>
#include "stackArray.h"

//need to practice this.
void pushbottom(s stackbottom,char item){

    if(stackbottom->top == MAX - 1){
        isFull(stackbottom);
        return;
    }

    for(int i = stackbottom->top; i > -1; i--){
        stackbottom->elem[i + 1] = stackbottom->elem[i];
    }

    stackbottom->elem[0] = item;
    stackbottom->top++;
}

int main()
{

    struct node mainstack;

    initStack(&mainstack);
    push(&mainstack, 'l');
    push(&mainstack, 'l');
    push(&mainstack, 'e');
    push(&mainstack, 'h');

    pushbottom(&mainstack, 'o');

    displayStack(&mainstack);

    return 0;
}