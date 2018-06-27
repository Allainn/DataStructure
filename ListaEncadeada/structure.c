#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

List* initList(){
    List *n = (List*) malloc(sizeof(List));
    n->inicio = NULL;
    return n;
}

No* mallocNo(int id){
    No *n = (No*) malloc(sizeof(No));
    n->id = id;
    n->prox =  NULL;
    return n;
}

void insertEndList(List *ptr, No *n){
    if(ptr->inicio == NULL){
        ptr->inicio = n;
        ptr->fim = n;
    }
    else {
        ptr->fim->prox = n;
        ptr->fim = n;
    }
}

void insertBeginList(List *ptr, No *n){
    if(ptr->inicio == NULL){
        ptr->inicio = n;
        ptr->fim = n;
    }
    else {
        n->prox = ptr->inicio;
        ptr->inicio = n;
    }
}

// void insertOrderList(List *ptr, No *n){
//     if(ptr->inicio == NULL){
//         ptr->inicio = n;
//         ptr->fim = n;
//     }
//     else {
//         No *aux1 = ptr->inicio;
//         No *aux2
//         if(n->id < ptr->inicio->id){
//             n->prox = ptr->inicio;
//             ptr->inicio = n;
//             return;
//         }
//         while(aux != NULL){
//             if(n->id < aux->id){

//             }
//         }
        
        
//         n->prox = ptr->inicio;
//         ptr->inicio = n;
//     }
// }


void removeList(List *ptr, int id);

void printList(No *ptr){
    if(ptr != NULL){
        printf("%d\t", ptr->id);
        printList(ptr->prox);
    }
}

void searchList(List* ptr, int id);

void clearList(List *ptr){
    No *aux;
    while(ptr->inicio != NULL){
        aux = ptr->inicio;
        ptr->inicio = aux->prox;
        free(aux);
    }
    free(ptr);
    printf("\nLista Limpada!!");
}