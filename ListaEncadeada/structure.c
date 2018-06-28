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

void insertOrderList(List *l, No *n){
    No *ptr = l->inicio;
    No* aux = NULL;
    
    while(ptr != NULL && n->id >= ptr->id){
        aux = ptr;
        ptr = ptr->prox;
    }

    if(aux == NULL){
        n->prox = l->inicio;
        l->inicio = n;
        //l->fim = n;
    }
    else{
        n->prox = aux->prox;
        aux->prox = n;
    }
}


void removeList(List *l, int id){
    for(No *ptr=l->inicio, *aux=NULL; ptr != NULL; aux=ptr, ptr=ptr->prox){
        if(ptr->id == id){
            if(ptr == l->inicio)
                l->inicio = ptr->prox;
            else if(ptr == l->fim){
                aux->prox = NULL;
                l->fim = aux;
            }
            else
                aux->prox = ptr->prox;
            printf("Removeu %d!!", ptr->id);
            free(ptr);
            return;
        }
    }
    printf("Não Achou %d", id);
}

void printList(List *l){
    for(No* ptr = l->inicio;ptr != NULL;ptr = ptr->prox)
        printf("%d\t", ptr->id);
}

void searchList(List* l, int id){
    for(No *ptr = l->inicio; ptr != NULL; ptr = ptr->prox)
        if(ptr->id == id){
            printf("Achou %d!!", ptr->id);
            return;
        }
    printf("Não Achou %d!!", id);
}

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