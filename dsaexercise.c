#include<stdio.h>
#include<stdbool.h>

#define MAX 100
typedef enum{
    TRUE, //0
    FALSE //1
}boolean;

typedef struct charList{
    char elem[MAX];
    int count;
}L;

bool findElem(L *foundlist){

    char target;    
    int index = -1;

    printf("Enter letter to be removed from the list: ");
    scanf(" %c", &target);

    for(int i = 0;i < foundlist->count && index == -1;i++){
        if(foundlist->elem[i] == target){
            index = i;
        }
        if(foundlist->elem[i] != target){
            printf("Element to be deleted is not in the list:\n");
            return FALSE;
        }
    }

    for(int i = 0;i < foundlist->count - 1; i++){
        foundlist->elem[i] = foundlist->elem[i + 1];
    }

    foundlist->count--;
    return TRUE;

}

int main(){

    L getlist;
    
    printf("Enter the limit of the array: ");
    scanf("%d", &getlist.count);

    if(getlist.count <= 0){
        printf("List is empty.");
        return 0;
    }

    printf("Enter %d letters: ",getlist.count);

    for(int i = 0;i < getlist.count; i++){
        scanf(" %c", &getlist.elem[i]);
    }

    findElem(&getlist);

    for(int i = 0;i < getlist.count;i++){
        printf("%c ",getlist.elem[i]);
    }
    return 0;
}