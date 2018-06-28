#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

int main(){

    Tree *t = initTree();

    insertTree(t, mallocNo(6));
    insertTree(t, mallocNo(8));
    insertTree(t, mallocNo(2));
    insertTree(t, mallocNo(9));
    insertTree(t, mallocNo(8));
    insertTree(t, mallocNo(5));

    printInOrderTree(t->root);

    printf("\n");
    return 0;
}