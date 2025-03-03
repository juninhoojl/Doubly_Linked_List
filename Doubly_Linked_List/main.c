//
//  main.c
//  Doubly_Linked_List
//
//  Created by José Luiz Junior on 4/24/20.
//  Copyright © 2020 José Luiz Junior. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

int main(int argc, const char * argv[]){
    
    hnode * lista = initialize_list();
    
    printf("Tamanho inicial = %d\n",lista->tam);
    
    int i = 0;
    
    int aleatorios[10]={5,7,1,2,9,4,3,6,8,0};
    //int aleatorios2[10]={-5,3,16,-2,5,4,-33,6,87,0};
    while(i++<10)<%
        insert_end(lista, new_node(i));
    %>
    
    show_list(lista);
    insert_end(lista, new_node(11));
    show_list(lista);
    
    insert_after(lista, search_node(lista, 10), new_node(88));
    show_list(lista);
    
    insert_before(lista, search_node(lista, 11), new_node(99));
    show_list(lista);
    
    remove_node(lista, search_node(lista, 3));
    show_list(lista);
    
    remove_all(lista);
    show_list(lista);
    
    for (i=0; i<10; i++){
        insert_sorting(lista, new_node(aleatorios[i]));
        printf("Valor = %d\n",aleatorios[i]);
    }
    
    show_list(lista);
    swap_nodes(lista, search_node(lista, 1), search_node(lista, 3));
    show_list(lista);
    swap_nodes(lista, search_node(lista, 3), search_node(lista, 4));
    show_list(lista);
    swap_nodes(lista, search_node(lista, 3), search_node(lista, 4));
    show_list(lista);
    swap_nodes(lista, search_node(lista, 0), search_node(lista, 2));
    show_list(lista);
    swap_nodes(lista, search_node(lista, 2), search_node(lista, 9));
    show_list(lista);

    show_node(node_max(lista));
    show_node(node_min(lista));
    
    
    return 0;
}
