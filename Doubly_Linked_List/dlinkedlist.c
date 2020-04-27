//
//  dlinkedlist.c
//  Doubly_Linked_List
//
//  Created by José Luiz Junior on 4/25/20.
//  Copyright © 2020 José Luiz Junior. All rights reserved.
//

#include "dlinkedlist.h"

void show_node(node * no){
    printf(" %d ", no->data);
    return;
}


node * node_min(hnode * cabeca){
    
    node * atual = cabeca->first;
    node * min = cabeca->first;
    
    while(atual->next){
        if(!compare_node(atual, atual->next)){
            min = atual->next;
        }
        atual = atual->next;
    }
    
    return min;
}
node * node_max(hnode * cabeca){
    
    node * atual = cabeca->first;
    node * max = cabeca->first;
    
    while(atual->next){
        if(compare_node(atual, atual->next)){
            max = atual->next;
        }
        atual = atual->next;
    }
    
    return max;
}

void swap_nodes(hnode * cabeca, node * first, node * second){

    node * aux = first->next;
    node * aux2 = second->prev;
    node * aux3 = first->prev;
    node * aux4 = second->next;

    if (!first->next){ // Ultimo
        cabeca->last = second;
    }else if (!first->prev){ // Primeiro
        cabeca->first = second;
    }
    
    if (!second->next){ // Ultimo
        cabeca->last = first;
    }else if (!second->prev){ // Primeiro
        cabeca->first = first;
    }
    

    if (first->next != second && second->next != first){ // Nao sao vizinhos
        
        if(first->prev){
            first->prev->next = second;
        }
        
        if(first->next){
            first->next->prev = second;
        }
        
        if(second->next){
            second->next->prev = first;
        }

        if(second->prev){
            second->prev->next = first;
        }
        
        first->next = aux4;
        second->next = aux;
        
        first->prev = aux2;
        second->prev = aux3;
        
    }else if(first->next == second){ //segundo é vizinho direito

        if(first->prev){ // Se nao eh nulo
            first->prev->next = second;
        }
        
        if(second->next){
            second->next->prev = first;
        }

        second->next = first;
        first->prev = second;
        second->prev = aux3;
        first->next = aux4;
        
        
    }else if(second->next == first){ // Segundo eh vizinho esquerdo
     // se existe algum depois do primerio o anterior dele aponta para o segundo
        
        if(first->next){
            first->next->prev = second;
        }
        
        if(second->prev){
            second->prev->next = first;
        }
        
        second->prev = first;
        second->next = aux4;
        first->prev = aux2;
        first->next = second;
        
    }
    
    
    
    return;
}

// 1-Primeiro maior 0-Iguais 1-Segundo maior
int compare_node(node * first, node * second){
    
    if(first->data > second->data){
        return 1;
        
    }else if(first->data < second->data){
        return -1;
        
    }
    
    return 0; // Iguais
}

node * new_node(int valor){
    
    node * newnode = (node*)malloc(sizeof(node));
    
    if(!newnode){
        printf("Memory allocation failed");
        exit(1);
    }
    
    newnode->data = valor;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    return newnode;
}


void insert_beggining(hnode * cabeca, node * newnode){

    //node * novo = new_node(valor);
    //novo->data = valor;
    newnode->next = cabeca->first;
    
    if (cabeca->first){
        cabeca->first->prev = newnode;
    }
    
    if (!cabeca->first){ // Se vazia
        cabeca->last = newnode;
    }
    
    cabeca->first = newnode;
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


void insert_end(hnode * cabeca, node * newnode){
    
    //node * novo = new_node(valor);
    //novo->data = valor;
    newnode->prev = cabeca->last;
    
    if (cabeca->last){
        cabeca->last->next = newnode;
    }
    
    if (!cabeca->first){
        cabeca->first = newnode;
    }
    
    cabeca->last = newnode;
    cabeca->tam+=1;
    
    return;
}

void insert_after(hnode * cabeca, node * anterior, node * newnode){
    
    if(!anterior->next){ // Se ultimo
        insert_end(cabeca,newnode);
        
    }else{
        //node * novo = new_node(valor);
        //novo->data = valor;
        newnode->prev = anterior;
        newnode->next = anterior->next;
        anterior->next = newnode;
        newnode->next->prev = newnode;
        cabeca->tam+=1;
    }
    
    return;
}

void insert_before(hnode * cabeca, node * proximo, node * newnode){
    
    if(cabeca->first == proximo){ // Se primeiro
        insert_beggining(cabeca, newnode);
    }else{
        //node * novo = new_node(valor);
        //novo->data = valor;
        newnode->prev = proximo->prev;
        newnode->next = proximo;
        
        proximo->prev->next = newnode;
        proximo->prev = newnode;

        cabeca->tam+=1;
    }
    
    return;
}

void show_list(hnode * cabeca){
    
    struct Node * atual = cabeca->first;
    
    //printf("Lista tamanho = %d\n", cabeca->tam);

    while(atual){
        show_node(atual);
        //printf("%d ", atual->data);
        atual = atual->next;
    }
    
    atual = cabeca->last;
    
//    printf("\nInvertido:\n");
//    while(atual){
//        show_node(atual);
//        //printf("%d ", atual->data);
//        atual = atual->prev;
//    }

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

void insert_sorting(hnode * cabeca, node * newnode){
    
    // Caminha ate achar alg
    struct Node * atual = cabeca->first;
    
    // 1 primeiro maior
    // -1 segundo maior
    // 0 iguais

    if(!atual || compare_node(atual, newnode) == 0 || compare_node(atual, newnode) == 1){
        // Se vazia ou menor insere no comeco
        insert_beggining(cabeca, newnode);
        printf("Insere Inicio\n");
    }else{
        while(atual->next!=NULL && compare_node(atual->next, newnode) == -1){
            atual = atual->next;
        }
        insert_after(cabeca, atual, newnode);
    }
    
    return;
}

hnode * initialize_list(void){
    hnode * novo = (hnode *)malloc(sizeof(hnode));
    novo->first = NULL;
    novo->last = NULL;
    novo->tam = 0;
    return novo;
}
