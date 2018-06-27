#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "ListaEncadeada/structure.h"

int main(){

    srand(time(NULL));

    List *Encad = initList();

    // insertEndList(Encad, mallocNo(rand()%10));
    // insertEndList(Encad, mallocNo(rand()%10));
    // insertEndList(Encad, mallocNo(rand()%10));
    // insertEndList(Encad, mallocNo(rand()%10));
    // insertEndList(Encad, mallocNo(rand()%10));
    // insertEndList(Encad, mallocNo(rand()%10));

    insertBeginList(Encad, mallocNo(1));
    insertBeginList(Encad, mallocNo(2));
    insertBeginList(Encad, mallocNo(3));
    insertBeginList(Encad, mallocNo(4));
    insertBeginList(Encad, mallocNo(5));
    insertBeginList(Encad, mallocNo(6));

    printList(Encad->inicio);

    clearList(Encad);

    printf("\n");
    return 0;
}