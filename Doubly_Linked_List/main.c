//
//  main.c
//  Doubly_Linked_List
//
//  Created by José Luiz Junior on 4/24/20.
//  Copyright © 2020 José Luiz Junior. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
  
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





void insert_beggining(hnode * cabeca, int valor){

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
    
    return;
}


void remove_all(hnode * cabeca){
    
    struct Node * atual = cabeca->first;
    struct Node * aux = NULL;
    
    while(atual){
        aux = atual;
        atual = atual->prev;
        free(aux);
    }
    
    cabeca->first = NULL;
    cabeca->last = NULL;
    cabeca->tam = 0;
    
    return;
}

void remove_node(hnode * cabeca, node * nremove){

    if(cabeca->first == nremove){ // Se primeiro
        
        cabeca->first = nremove->next;
        nremove->next->prev = NULL;
        
    }else if(cabeca->last == nremove){ // Se ultimo
        
        cabeca->last = nremove->prev;
        nremove->prev->next = NULL;
        
    }else{
        
        nremove->prev->next = nremove->next;
        nremove->next->prev = nremove->prev;
        
    }
    
    free(nremove);
    
    cabeca->tam-=1;
    
    return;
}


void insert_end(hnode * cabeca, int valor){
    
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

void insert_after(hnode * cabeca, node * anterior, int valor){
    
    if(!anterior->next){ // Se ultimo
        insert_end(cabeca,valor);
        
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

void insert_before(hnode * cabeca, node * proximo, int valor){
    
    
    if(cabeca->first == proximo){ // Se primeiro
        insert_beggining(cabeca, valor);
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

void show_list(hnode * cabeca){
    
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


node * search_node(hnode * cabeca, int valor){
    
    struct Node * atual = cabeca->first;

    while(atual && atual->data!=valor){
        atual = atual->next;
    }

    if(atual){
        return atual;
    }
    
    return NULL;
}

void insert_sorting(hnode * cabeca, int valor){
    
    // Caminha ate achar alg
    struct Node * atual = cabeca->first;
    
    if(!atual || atual->data >= valor){// Se vazia insere no comeco
        insert_beggining(cabeca, valor);
        printf("Insere Inicio\n");
    }else{
        while(atual->next!=NULL && atual->next->data < valor){
            atual = atual->next;
        }
        insert_after(cabeca, atual, valor);
    }
    
    return;
}

hnode * initialize_list(){
    hnode * novo = (hnode *)malloc(sizeof(hnode));
    novo->first = NULL;
    novo->last = NULL;
    novo->tam = 0;
    return novo;
}

int main(int argc, const char * argv[]) {
    
    hnode * lista = initialize_list();
    
    printf("Tamanho inicial = %d\n",lista->tam);
    
    int i = 0;
    
    int aleatorios[10]={5,7,1,2,9,4,3,6,8,0};
    int aleatorios2[10]={-5,3,16,-2,5,4,3,6,8,0};
    while(i++<10)<%
        insert_end(lista, i);
    %>
    
    show_list(lista);
    insert_end(lista, 11);
    show_list(lista);
    
    printf("Tamanho = %d\n",search_node(lista, 8)->next->data);
    
    insert_after(lista, search_node(lista, 10), 88);
    show_list(lista);
    
    insert_before(lista, search_node(lista, 11), 99);
    show_list(lista);
    
    remove_node(lista, search_node(lista, 3));
    show_list(lista);
    
    remove_all(lista);
    show_list(lista);
    
    for (i=0; i<10; i++){
        insert_sorting(lista, aleatorios[i]);
        printf("Valor = %d\n",aleatorios[i]);
    }
    
     show_list(lista);
    
    for (i=0; i<10; i++){
        insert_sorting(lista, aleatorios2[i]);
        printf("Valor = %d\n",aleatorios2[i]);
    }
    
     show_list(lista);
    
    return 0;
}
