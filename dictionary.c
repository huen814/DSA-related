#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Implementation and fixing of handwritten codes from October 1,2026 Discussion

#define MAX 10
typedef enum
{
    FALSE,
    TRUE
} booltype;

typedef struct cell
{
    int data;
    struct cell *link;
} *Plist, list;

typedef Plist Dictionary[MAX];

int Hash(int elem);
void initDictionary(Dictionary A);
void insert(Dictionary A, int elem);
void delete(Dictionary A, int elem);
bool member(Dictionary A, int elem);
void insertSortedUnique(Dictionary A, int elem);
void display(Dictionary A);

int Hash(int elem)
{

    return (elem % MAX);
}

void initDictionary(Dictionary A)
{

    for (int i = 0; i < MAX; i++)
    {
        A[i] = NULL;
    }
}

void insert(Dictionary A, int elem)
{

    Plist *trav;
    int pos = Hash(elem);
    Plist temp = (Plist)malloc(sizeof(struct cell));

    for (trav = &A[pos]; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->link){}

    temp->data = elem;
    temp->link = *trav;
    *trav = temp;
}

void delete(Dictionary A, int elem)
{

    Plist *trav, temp;
    int pos = Hash(elem);

    for (trav = &A[pos]; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    temp = *trav;
    *trav = temp->link;
    free(temp);
}

bool member(Dictionary A, int elem)
{

    Plist *trav;
    int pos = Hash(elem);

    for (trav = &A[pos]; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}

    return (*trav != NULL) ? TRUE : FALSE;
}

void insertSortedUnique(Dictionary A, int elem)
{

    Plist *trav, temp = NULL;
    int pos = Hash(elem);

    for (trav = &A[pos]; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->link){}

    if (*trav == NULL || (*trav)->data != elem)
    {
        temp = (Plist)malloc(sizeof(struct cell));
        if (temp != NULL)
        {
            temp->data = elem;
            temp->link = *trav;
            *trav = temp;
        }
    }
}

void display(Dictionary A)
{

    Plist trav;
    int i;

    for (i = 0; i < MAX; i++)
    {
        printf("INDEX: %d - ", i);
        for (trav = A[i]; trav != NULL; trav = trav->link)
        {
            printf("%d ", trav->data);
        }
        printf("\n");
    }
}

int main()
{

    Dictionary m;

    initDictionary(m);

    insert(m, 10);
    insert(m, 20);
    insert(m, 15);
    insert(m, 30);
    insertSortedUnique(m,5);
    member(m,20);

    display(m);

    printf("\n%s\n",member(m,20) ? "found" : "not found");
    printf("\n--------------\n\n");

    delete(m,10);

    display(m);

    return 0;
}