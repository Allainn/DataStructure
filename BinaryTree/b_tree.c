#include <stdio.h>
#include <stdlib.h>
#include "b_tree.h"

Tree* initTree(){
    Tree *n = (Tree*) malloc(sizeof(Tree));
    n->root = NULL;
    return n;
}

No* mallocNo(int id){
    No* n = (No*) malloc(sizeof(No));
    n->id = id;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void insertTree(Tree *t, No *n){
    No *ptr = t->root;
    if(t->root == NULL)
        t->root = n;
    else{
        while(ptr != NULL){
            if(n->id < ptr->id){
                if(ptr->left == NULL){
                    ptr->left = n;
                    return;
                }
                else
                    ptr = ptr->left;
            }
            else{
                if(ptr->right == NULL){
                    ptr->right = n;
                    return;
                }
                else
                    ptr = ptr->right;
            }    
        }
    }
}



void printInOrderTree(No *ptr){
    if(ptr != NULL){
        printInOrderTree(ptr->left);
        printf("%d\t", ptr->id);
        printInOrderTree(ptr->right);
    }
}

void printPreOrderTree(No *ptr){
    if(ptr != NULL){
        printPreOrderTree(ptr->left);
        printPreOrderTree(ptr->right);
        printf("%d\t", ptr->id);
    }
}


void printPostOrderTree(No *ptr){
    if(ptr != NULL){
        printf("%d\t", ptr->id);
        printPostOrderTree(ptr->left);
        printPostOrderTree(ptr->right);
    }
}


void removeNoTree(Tree *t, int id);
void searchNoTree(Tree *t, int id);