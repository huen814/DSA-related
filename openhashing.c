#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10

// Node structure for linked list bucket
typedef struct node {
    char elem;
    struct node *next;
} Node, *NodePtr;

typedef NodePtr OpenDict[MAX];

int HASH(char key) {
    return (toupper(key) - 'A') % MAX;
}

void displayDict(OpenDict D) {
    printf("\n--- OPEN HASH DICTIONARY (Chaining) ---\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d]: ", i);
        NodePtr trav = D[i];
        while (trav != NULL) {
            printf("%c -> ", trav->elem);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

// TODO EXERCISES FOR STUDENTS:

void initDict(OpenDict D) {
    // TODO: Loop through array D and set every bucket pointer to NULL

    for(int i = 0; i < MAX; i++){
        D[i] = NULL;
    }
}

void insertDict(OpenDict D, char elem) {
    // TODO: Hash elem, malloc a new node, and insert at head of list at D[HASH(elem)]

    int e = HASH(elem);

    NodePtr node = malloc(sizeof(struct node));
    if(node != NULL){
        node->elem = elem;
        node->next = D[e];
        D[e] = node;
    }

}

void deleteDict(OpenDict D, char elem) {
    // TODO: Search linked list at D[HASH(elem)], unlink target node, and free memory
    int e = HASH(elem);
    NodePtr *trav,temp;

    for(trav = &D[e]; (*trav) != NULL && (*trav)->elem != elem;trav = &(*trav)->next){}

    temp = *trav;
    *trav = temp->next;
    free(temp);

}

int main() {
    OpenDict D;
    initDict(D);

    printf("Inserting 'A', 'K', 'U' (All hash to index 0)...\n");
    insertDict(D, 'A');
    insertDict(D, 'K');
    insertDict(D, 'U');
    displayDict(D);

    printf("Deleting 'K'...\n");
    deleteDict(D, 'K');
    displayDict(D);

    return 0;
}
