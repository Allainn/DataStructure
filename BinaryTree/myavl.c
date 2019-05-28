#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "b_tree.h"

int main()
{
    int he, hd;

    Tree *t = initTree();

    insertTree(t, mallocNo(6));
    insertTree(t, mallocNo(4));
    insertTree(t, mallocNo(5));


    printInOrderTree(t->root,0);

    leftRotation(t,t->root->left);
    rightRotation(t,t->root);
    
    updateFB(t->root);
    printf("\n");

    printInOrderTree(t->root,0);

    //printf("\n%d", heightTree(t->root));

    //printf("\n%d", t->root->right->id);

    printf("\n");
    return 0;
}