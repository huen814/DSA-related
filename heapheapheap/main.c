#include <stdio.h>
#include "golem.h"

int main() {
    MaxHeap H;
    int n, i, w, result;
    initHeap(&H);

    printf("N (number of golems): ");
    scanf("%d", &n);

    printf("N golem weights: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &w);
        insert(&H, w);
    }

    result = lastGolem(&H);

    printf("\n");
    if (result == 0) printf("Arena is empty. No golem survives!\n");
    else printf("Champion golem weight: %d\n", result);

    return 0;
}
