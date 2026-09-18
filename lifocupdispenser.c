#include <stdio.h>

// Mission 1

#define MAX 10
typedef int Product;

typedef struct stack
{
    int data[MAX];
    int top;
} Qptr;

void stackPush(Qptr *q, Product po)
{
    if (q->top != MAX - 1)
    {
        q->top = q->top + 1;
        q->data[q->top] = po;
    }
}

void stackPop(Qptr *q)
{

    if (q->top != -1)
    {
        q->top = q->top - 1;
    }
}

void display(Qptr *q)
{

    if (q->top != -1)
    {
        printf("\nCups: ");
        for (int i = 0; i <= q->top; i++)
        {
            printf("%d ", q->data[i]);
        }
    }
    else
    {
        printf("Queue is empty...\n\n");
    }

    printf("\n\n");
}

int main()
{

    Qptr coffee;
    coffee.top = -1;
    Product p;
    int option = 0;

    do
    {
        printf("The LIFO CUP DISPENSER\n");
        printf("Reminder to Customers: The last cup placed in must be the first cup taken out ;)");
        printf("GET IN LINE!\n");
        printf("1. Add a cup (Push -> Staff restocks)\n");
        printf("2. Take a cup (Pop -> Customer removes the top cup)\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter Cup ID: ");
            scanf("%d", &p);
            printf("\nRestocked the cups!\n\n");
            stackPush(&coffee, p);
            break;
        case 2:
            printf("\nCustomer took a cup from the top!\n\n");
            stackPop(&coffee);
            break;
        case 3:
            display(&coffee);
            break;
        }

    } while (option != 4);

    return 0;
}
