//
//  main.c
//  Doubly_Linked_List
//
//  Created by José Luiz Junior on 4/24/20.
//  Copyright © 2020 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
  
// A linked list node
typedef struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
}node;

typedef struct Hnode {
    int tam;
    struct Node * first;
    struct Node * last;
}hnode;


void insere_inicio(hnode * cabeca, int valor){

    node * novo = (node*)malloc(sizeof(node));
  
    novo->data = valor;
    novo->prev = NULL;
    novo->next = cabeca->first;
    
    if (cabeca->first){
        cabeca->first->prev = novo;
    }
    
    if (cabeca->tam == 0){
        cabeca->last = novo;
    }
    
    cabeca->first = novo;
    cabeca->tam+=1;
    
}


void insere_fim(hnode * cabeca, int valor){
    
    node * novo = (node*)malloc(sizeof(node));
    
    novo->data = valor;
    novo->next = NULL;
    novo->prev = cabeca->last;
    
    if (cabeca->last){
        cabeca->last->next = novo;
    }
    
    if (cabeca->tam == 0){
        cabeca->first = novo;
    }
    
    cabeca->last = novo;
    cabeca->tam+=1;
    
    return;
}

void insere_depois(hnode * cabeca, node * anterior, int valor){
    
    if(!anterior->next){ // Se ultimo
        insere_fim(cabeca,valor);
        
    }else{
        node * novo = (node*)malloc(sizeof(node));
        novo->data = valor;
        novo->prev = anterior;
        novo->next = anterior->next;
        anterior->next = novo;
        novo->next->prev = novo;
        cabeca->tam+=1;
    }
    
    return;
}

void insere_antes(hnode * cabeca, node * proximo, int valor){
    
    
    if(cabeca->first == proximo){ // Se primeiro
        insere_inicio(cabeca, valor);
    }else{
        node * novo = (node*)malloc(sizeof(node));
        novo->data = valor;
        novo->prev = proximo->prev;
        novo->next = proximo;
        
        proximo->prev->next = novo;
        proximo->prev = novo;

        cabeca->tam+=1;
    }
    
    return;
}

void mostra_lista(hnode * cabeca){
    
    struct Node * atual = cabeca->first;
    
    printf("Lista tamanho = %d\n", cabeca->tam);

    printf("Normal:\n");
    while(atual){
        printf("%d ", atual->data);
        atual = atual->next;
    }
    
    atual = cabeca->last;
    
    printf("\nInvertido:\n");
    while(atual){
        printf("%d ", atual->data);
        atual = atual->prev;
    }

    printf("\n");
    
    return;
}


node * busca_node(hnode * cabeca, int valor){
    
    struct Node * atual = cabeca->first;

    while(atual && atual->data!=valor){
        atual = atual->next;
    }

    if(atual){
        return atual;
    }
    
    return NULL;
}



hnode * inicia_lista(){
    hnode * novo = (hnode *)malloc(sizeof(hnode));
    novo->first = NULL;
    novo->last = NULL;
    novo->tam = 0;
    return novo;
}

int main(int argc, const char * argv[]) {
    
    hnode * lista = inicia_lista();
    
    printf("Tamanho inicial = %d\n",lista->tam);
    
    int i = 0;
    
    
    while(i++<10)<%
        insere_fim(lista, i);
    %>
    
    mostra_lista(lista);
    insere_fim(lista, 11);
    mostra_lista(lista);
    
    printf("Tamanho = %d\n",busca_node(lista, 8)->next->data);
    
    insere_depois(lista, busca_node(lista, 10), 88);
    mostra_lista(lista);
    
    insere_antes(lista, busca_node(lista, 11), 99);
    mostra_lista(lista);
    
    return 0;
}
