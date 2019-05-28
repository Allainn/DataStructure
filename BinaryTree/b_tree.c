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
    n->father = NULL;
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
                    n->father = ptr;
                    break;
                }
                else
                    ptr = ptr->left;
            }
            else{
                if(ptr->right == NULL){
                    ptr->right = n;
                    n->father = ptr;
                    break;
                }
                else
                    ptr = ptr->right;
            }    
        }
    }
    updateFB(t->root);
}

void rotacaoDireita(Tree *t, No *ptr){
    No *aux = ptr->left;
    
    ptr->left = aux->right;
    ptr->left->father = ptr;
    
    aux->right = ptr;
    aux->father = ptr->father;

    ptr->father = aux;

    if(ptr != t->root){
        if(aux->father->left == ptr)
            aux->father->left = aux;
        else
            aux->father->right = aux;
    }
    else
        t->root = aux;
}

void rotacaoEsquerda(Tree *t, No *ptr){
    No *aux = ptr->right;
    
    ptr->right = aux->left;
    ptr->right->father = ptr;
    
    aux->left = ptr;
    ptr->father = aux;
    
    aux->father = ptr->father;

    if(ptr != t->root){
        if(aux->father->left == ptr)
            aux->father->left = aux;
        else
            aux->father->right = aux;
    }
    else
        t->root = aux;
}

void updateFB(No *ptr){
    if(ptr != NULL){
        ptr->fb = heightTree(ptr->left) - heightTree(ptr->right);
        // if(ptr->fb == 2){
        //     if(ptr->left->fb == 1){

        //     }
        // }
        updateFB(ptr->left);
        updateFB(ptr->right);
    }
}


void printInOrderTree(No *ptr){
    if(ptr != NULL){
        printInOrderTree(ptr->left);
        printf("%d,%d\t", ptr->id, ptr->fb);
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

int heightTree(No *ptr){
    if(ptr == NULL)
        return 0;
    else {
        int he = heightTree(ptr->left);
        int hd = heightTree(ptr->right);
        if(he < hd) return hd + 1;
        else return he + 1;
    } 
}


void removeNoTree(Tree *t, int id);

No* searchNoTree(Tree *t, int id){
    // if(t == NULL)
    //     return NULL;
    // if(t->root != NULL) 
}