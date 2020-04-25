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

void insert_beggining(hnode * cabeca, int valor);
void remove_all(hnode * cabeca);
void remove_node(hnode * cabeca, node * nremove);
void insert_end(hnode * cabeca, int valor);
void insert_after(hnode * cabeca, node * anterior, int valor);
void insert_before(hnode * cabeca, node * proximo, int valor);
void show_list(hnode * cabeca);
node * search_node(hnode * cabeca, int valor);
void insert_sorting(hnode * cabeca, int valor);
hnode * initialize_list(void);



#endif /* dlinkedlist_h */
