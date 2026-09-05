#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 10

typedef struct node{
    char elem[MAX];
    struct node *link;
}*charList;

bool findElem(charList find,int limit);
bool deleteElem(charList delete,int limit);

bool findElem(charList find,int limit){

    char target;

    printf("Enter element you want to find: ");
    scanf(" %c", &target);

    for(int i = 0; i < limit; i++){
        if(find->elem[i] == target){
            printf("\nTarget found.");
            return true;
        }
    }

    printf("\nTarget element not found in list.\n");
    
    return false;
}   

bool deleteElem(charList delete,int limit){

    char target;
    bool found = false;

    printf("Enter element to be deleted: ");
    scanf(" %c", &target);
    for(int i = 0; i < limit; i++){
        if(delete->elem[i] == target){
            found = true;
            for(int j = i; j < limit - 1; j++){
                delete->elem[j] = delete->elem[j + 1];
            }
        }
    }

        if(found == true){
        printf("List after deleting targeted element:\n");
        for(int i = 0; i < limit - 1; i++){
            printf("%c ",delete->elem[i]);
        }
    }

    printf("\nElement is not found in list...\n");
    
    return found;
}

int main(){

    charList getchar = NULL;  
    int option = 0;
    int limit = 10;

    getchar = (charList)malloc(sizeof(struct node));
    //I haven't figured out yet how to have the program take less than 10 characters. :>
    printf("Enter 10 values (characters): ");
    for(int i = 0; i < limit;i++){
    scanf(" %c", &getchar->elem[i]);
    }

    printf("Entered values: ");
    for(int i = 0; i < limit;i++){
    printf("%c ", getchar->elem[i]);
    }

    printf("\nEnter option:\n");
    printf("1. Find Elem\n");
    printf("2. Delete Elem\n");
    scanf("%d", &option);

    switch(option){
    case 1:
    findElem(getchar,limit);
    break;
    case 2:
    deleteElem(getchar,limit);
    break;
    }

    return 0;
}