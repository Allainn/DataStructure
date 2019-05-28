#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "b_tree.h"

int main()
{
    Tree *t = initTree();
    char op;
    int val;
    int cont = 0;
    // while (cont<12)
    // {
    //     scanf("%c%d", &op, &val);
    //     if(op == 'i'){
    //         printf("%d\n", cont);
    //         insertTree(t, mallocNo(val));
    //     }
    //     cont+=1;
    // }

    insertTree(t, mallocNo(10));
    insertTree(t, mallocNo(20));
    insertTree(t, mallocNo(30));
    insertTree(t, mallocNo(40));
    insertTree(t, mallocNo(50));
    insertTree(t, mallocNo(45));
    insertTree(t, mallocNo(48));
    removeNoTree(t, 40);
    insertTree(t, mallocNo(5));
    insertTree(t, mallocNo(4));
    insertTree(t, mallocNo(3));
    removeNoTree(t, 50);
    removeNoTree(t, 45);

    printInOrderTree(t->root, 0);

    clear(t->root);
    free(t);

    printf("\n");
    return 0;
}