#include <stdio.h>
#include "golem.h"

/*  TODO: Return the weight of the last surviving golem, or 0 if none.
    Available: size(*H), isEmpty(*H), deleteMax(H), insert(H, x), peekMax(*H) */
    
int lastGolem(MaxHeap *H) {
    // Code here...

    int g1;
    int g2;

    while(size(*H) > 1){
        g1 = deleteMax(H);
        g2 = deleteMax(H);
    if(g1 != g2){
        insert(H,g1 - g2);
        }
    }

return(isEmpty(*H) ? 0 : peekMax(*H));
}
