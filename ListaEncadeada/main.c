#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "structure.h"

int main()
{

    srand(time(NULL));

    List *Encad = initList();

    // insertEndList(Encad, mallocNo(rand() % 10));
    // insertEndList(Encad, mallocNo(rand() % 10));
    // insertEndList(Encad, mallocNo(rand() % 10));
    // insertEndList(Encad, mallocNo(rand() % 10));
    // insertEndList(Encad, mallocNo(rand() % 10));
    // insertEndList(Encad, mallocNo(rand() % 10));

    // insertBeginList(Encad, mallocNo(1));
    // insertBeginList(Encad, mallocNo(2));
    // insertBeginList(Encad, mallocNo(3));
    // insertBeginList(Encad, mallocNo(4));
    // insertBeginList(Encad, mallocNo(5));
    // insertBeginList(Encad, mallocNo(6));

    insertOrderList(Encad, mallocNo(34));
    insertOrderList(Encad, mallocNo(65));
    insertOrderList(Encad, mallocNo(76));
    insertOrderList(Encad, mallocNo(12));
    insertOrderList(Encad, mallocNo(45));
    insertOrderList(Encad, mallocNo(85));

    printList(Encad);

    printf("\n");
    removeList(Encad, 76);
    removeList(Encad, 12);
    removeList(Encad, 85);

    printf("\n");
    printList(Encad);

    clearList(Encad);

    printf("\n");
    return 0;
}