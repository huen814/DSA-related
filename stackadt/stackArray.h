#include <stdio.h>
#ifndef STACK_H
#define STACK_H

#define MAX 10

typedef struct node
{
    char elem[MAX];
    int top;
} *s;

void initStack(s stack);
void push(s stackpush, char item);
void pop(s stackpop);
void top(s checktop);
void isEmpty(s isempty);
void isFull(s isfull);
void displayStack(s displaystack);

void initStack(s stack)
{

    stack->top = -1;
}

void push(s stackpush, char item)
{

    if (stackpush->top != MAX - 1)
    {
        stackpush->top++;
        stackpush->elem[stackpush->top] = item;
    }
}

void pop(s stackpop)
{

    if (stackpop->top != -1)
    {
        stackpop->top--;
    }
}

void top(s checktop)
{

    if (checktop->top != -1)
    {
        printf("%c", checktop->elem[checktop->top]);
    }
}

void isEmpty(s isempty)
{

    if (isempty->top == -1)
    {
        printf("Stack is empty.");
    }
}

void isFull(s isfull)
{

    if (isfull->top == MAX - 1)
    {
        printf("Stack is full.");
    }
}

void displayStack(s displayStack)
{

    for (int i = displayStack->top; i >= 0; i--)
    {
        printf("%c", displayStack->elem[i]);
    }
}

#endif