#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "b_tree.h"

int main()
{

    srand(time(NULL));

    Tree *t = initTree();

    insertTree(t, mallocNo(63));
    insertTree(t, mallocNo(56));
    insertTree(t, mallocNo(45));
    insertTree(t, mallocNo(78));
    insertTree(t, mallocNo(84));
    insertTree(t, mallocNo(34));
    insertTree(t, mallocNo(23));
    insertTree(t, mallocNo(87));
    insertTree(t, mallocNo(64));
    insertTree(t, mallocNo(21));
    insertTree(t, mallocNo(75));

    printInOrderTree(t->root);

    printf("\n%d", heightTree(t->root->left));

    printf("\n%d", t->root->left->father->id);

    printf("\n");
    return 0;
}