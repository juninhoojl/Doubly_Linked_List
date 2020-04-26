//
//  dlinkedlist.h
//  Doubly_Linked_List
//
//  Created by José Luiz Junior on 4/25/20.
//  Copyright © 2020 José Luiz Junior. All rights reserved.
//

#ifndef dlinkedlist_h
#define dlinkedlist_h

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

void insert_beggining(hnode * cabeca, node * newnode);
void insert_end(hnode * cabeca, node * newnode);
void insert_after(hnode * cabeca, node * anterior, node * newnode);
void insert_before(hnode * cabeca, node * proximo, node * newnode);
void insert_sorting(hnode * cabeca, node * newnode);

void remove_all(hnode * cabeca);
void remove_node(hnode * cabeca, node * nremove);
void show_list(hnode * cabeca);


hnode * initialize_list(void);
// 1-Primeiro maior 0-Iguais 1-Segundo maior
int compare_node(node * first, node * second);
// Novo node
node * new_node(int valor);
// buca node
node * search_node(hnode * cabeca, int valor);
#endif /* dlinkedlist_h */
