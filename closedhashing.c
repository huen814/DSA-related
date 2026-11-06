#include <stdio.h>
#include <ctype.h>

#define MAX 10
#define EMPTY '?'
#define DELETED '!'

typedef char LinearDict[MAX];

int HASH(char key) {
    return (toupper(key) - 'A') % MAX;
}

void displayDict(LinearDict D) {
    printf("\n--- CLOSED HASH DICTIONARY (Linear Probing) ---\n");
    printf("%5s | %-5s\n", "IDX", "DATA");
    printf("%5s | %5s\n", "----", "----");
    for (int i = 0; i < MAX; i++) {
        printf(" %5d  |  %-5c\n", i, D[i]);
    }
}

// TODO EXERCISES FOR STUDENTS:

void initDict(LinearDict D) {
    // TODO: Loop through array and initialize all slots to EMPTY ('?')

    for(int i = 0;i < MAX;i++){
        D[i] = '?';
    }

}

void insertDict(LinearDict D, char elem) {
    // TODO: Use probing formula (HASH(elem) + i) % MAX to find first EMPTY or DELETED slot
    int e = HASH(elem);

    for(int i = 0;i < MAX; i++){
        int idx = (e + i) % MAX;
        if(D[idx] == '?' || D[idx] == '!'){
            D[idx] = elem;
            break;
        }
    }

}

void deleteDict(LinearDict D, char elem) {
    // TODO: Search sequentially starting at HASH(elem) until element is found or EMPTY hit
    // Mark target slot as DELETED ('!')
    int e = HASH(elem);

    for(int i = 0; i < MAX; i++){
        int idx = (e + i) % MAX;
        if(D[idx] == elem){
            D[idx] = '!';
            break;
        }
    }
}

int main() {
    LinearDict D;
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
