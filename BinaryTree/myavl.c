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
    int flag = 0;
    while(1){
        scanf("%c%d", &op, &val);
        if(op=='\n') { 
            flag++;
            if(flag == 2) break;
            continue;
        }
        flag = 0;
        //printf("%c,%d\n", op, val);
        switch (op)
        {
        case 'i':
            insertTree(t, mallocNo(val));
            break;
        
        case 'r':
            removeNoTree(t, val);
            break;
        default:
            break;
        }
    }

    printInOrderTree(t->root, 0);

    clear(t->root);
    free(t);

    return 0;
}