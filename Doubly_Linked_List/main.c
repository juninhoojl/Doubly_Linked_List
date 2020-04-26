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
    int aleatorios2[10]={-5,3,16,-2,5,4,-33,6,87,0};
    while(i++<10)<%
        insert_end(lista, new_node(i));
    %>
    
    show_list(lista);
    insert_end(lista, new_node(11));
    show_list(lista);
    
    printf("Tamanho = %d\n",search_node(lista, 8)->next->data);
    
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
    
    for (i=0; i<10; i++){
        insert_sorting(lista, new_node(aleatorios2[i]));
        printf("Valor = %d\n",aleatorios2[i]);
    }
    
    show_list(lista);
    swap_nodes(search_node(lista, 87), search_node(lista, -33));
    show_list(lista);
    
    return 0;
}
