/*****************************************************************
* 
*  Algoritimo responsvel por interações em uma arvore binaria
*  
*  Autor: Allainn Christiam
*          
******************************************************************/
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
    n->fb = 0;
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
    updateFB(t, t->root);
}

void updateFB(Tree *t, No *ptr){
    if(ptr != NULL){
        updateFB(t, ptr->left);
        updateFB(t, ptr->right);
        ptr->fb = heightTree(ptr->left) - heightTree(ptr->right);
        if(ptr->fb == 2){
            ptr->left->fb = heightTree(ptr->left->left) - heightTree(ptr->left->right);
            if(ptr->left->fb >= 0){
                rightRotation(t, ptr);
            }
            else {
                leftRotation(t, ptr->left);
                rightRotation(t, ptr);
            }
            updateFB(t, t->root);
            return;
        }
        if(ptr->fb == -2){
            ptr->right->fb = heightTree(ptr->right->left) - heightTree(ptr->right->right);
            if(ptr->right->fb <= 0){
                leftRotation(t, ptr);
            }
            else {
                rightRotation(t, ptr->right);
                leftRotation(t, ptr);
            }
            updateFB(t, t->root);
            return;
        }
    }
}

void rightRotation(Tree *t, No *ptr){
    No *aux = ptr->left;
    
    ptr->left = aux->right;
    if(ptr->left != NULL)
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

void leftRotation(Tree *t, No *ptr){    
    No *aux = ptr->right;
    
    ptr->right = aux->left;
    if(ptr->right != NULL)
        ptr->right->father = ptr;
    
    aux->left = ptr;
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

void printInOrderTree(No *ptr, int i){
    if(ptr != NULL){
        printInOrderTree(ptr->left, i+1);
        printf("%d,%d\n", ptr->id,i);
        printInOrderTree(ptr->right, i+1);
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

void clear(No *ptr){
    if(ptr!=NULL){
        clear(ptr->left);
        clear(ptr->right);
        free(ptr);
    }

}

void removeNoTree(Tree *t, int id){
    No* ptr = searchNoTree(t, id);
    if(ptr != NULL){
        if(ptr->left == NULL && ptr->right == NULL){
            if(ptr->father == NULL)
                t->root = NULL;
            else {
                if(ptr->father->right == ptr)
                    ptr->father->right = NULL;
                else{
                    ptr->father->left = NULL;
                }
            }
        }
        else{
            if(ptr->left == NULL){
                if(ptr->father == NULL)
                    t->root = ptr->right;
                else {
                    if(ptr->father->right == ptr)
                        ptr->father->right = ptr->right;
                    else
                        ptr->father->left = ptr->right;
                }
                ptr->right->father = ptr->father;
            }
            else if(ptr->right == NULL){
                if(ptr->father == NULL)
                    t->root = ptr->left;
                else {
                    if(ptr->father->right == ptr)
                        ptr->father->right = ptr->left;
                    else
                        ptr->father->left = ptr->left;
                }
                ptr->left->father = ptr->father;
            }
            else {
                if(ptr->father == NULL)
                    t->root = ptr->left;
                else {
                    if(ptr->father->right == ptr)
                        ptr->father->right = ptr->left;
                    else
                        ptr->father->left = ptr->left;
                }
                No *aux = ptr->left;
                aux->father = ptr->father; 
                while(aux->right != NULL)
                    aux = aux->right;
                aux->right = ptr->right;
                ptr->right->father = aux;
            }
        }
        free(ptr);
        updateFB(t,t->root);
    }
}

No* searchNoTree(Tree *t, int id){
    if(t == NULL)
         return NULL;
    if(t->root != NULL) {
        No* ptr = t->root;
        while(ptr != NULL){
            if(id == ptr->id)
                return ptr;
            else {
                if(id > ptr->id)
                    ptr = ptr->right;
                else 
                    ptr = ptr->left;
            }
        }
        return NULL;
    }
}