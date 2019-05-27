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


    printInOrderTree(t->root);

    printf("\n%d", heightTree(t->root));

    printf("\n%d", t->root->id);

    printf("\n");
    return 0;
}