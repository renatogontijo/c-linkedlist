/* 
 * File:   main.c
 * Author: gontijo
 *
 * Created on May 8, 2012, 7:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*
 * 
 */

void intTest() {
    struct linkedlist *linkedlist;
    struct llnode *li_aux;
    struct llnode *li_0;
    int values[] = {1, 2, 3, 4, 5};
    char cvalues[] = {'a', 'e', 'i', 'o', 'u'};
    
    linkedlist = LinkedListCreate(T_INT);
    li_0 = LinkedListAddLast(linkedlist, values[0]);
    li_aux = LinkedListAddLast(linkedlist, values[1]);
    li_aux = LinkedListAddLast(linkedlist, values[2]);
    li_aux = LinkedListAddLast(linkedlist, values[3]);
    li_aux = LinkedListAddLast(linkedlist, values[4]);
    li_aux = LinkedListAddFirst(linkedlist, (int *)10);
    li_aux = LinkedListAddFirst(linkedlist, (int *)11);
    li_aux = LinkedListAddFirst(linkedlist, (int *)1);
    
    printf("%i\n\n", LinkedListCompData(linkedlist, li_0->data, li_aux->data));
    
    // Remove o item 1
    //LinkedListRemove(linkedlist, li_aux, 1);
    
    // Lista conteúdo da lista
    li_aux = LinkedListIterator(linkedlist);
    while((li_aux = LinkedListNext(linkedlist, li_aux)) != NULL)
        printf("%i\n", ((int *)li_aux->data));
    
    printf("\n\n");
    //LinkedListClear(linkedlist);
    

    // Lista conteúdo da lista inversamente
    li_aux = LinkedListReverseIterator(linkedlist);
    while((li_aux = LinkedListNext(linkedlist, li_aux)) != NULL)
        printf("%i\n", (int *)li_aux->data);

    // Primeiro
    li_aux = LinkedListFirst(linkedlist);
    if(li_aux != NULL)
        printf("Primeiro=%i\n", (int *)li_aux->data);
    
    // Último
    li_aux = LinkedListLast(linkedlist);
    if(li_aux != NULL)
        printf("Ultimo=%i\n", (int *)li_aux->data);
    
    // Conta a quantidade de registros
    printf("count = %i", LinkedListCount(linkedlist));    
}

void strTest() {
    struct linkedlist *linkedlist;
    struct llnode *li_aux;
    struct llnode *li_0;
    int values[] = {1, 2, 3, 4, 5};
    char *cvalues[] = {"a", "b"};
    
    linkedlist = LinkedListCreate(T_STR);
    li_0 = LinkedListAddLast(linkedlist, (char *)cvalues[0]);
    li_aux = LinkedListAddLast(linkedlist, (char *)cvalues[1]);
    li_aux = LinkedListAddLast(linkedlist, "c");
    li_aux = LinkedListAddLast(linkedlist, "d");
    li_aux = LinkedListAddLast(linkedlist, "e");
    li_aux = LinkedListAddFirst(linkedlist, "abc");
    li_aux = LinkedListAddFirst(linkedlist, "def");
    li_aux = LinkedListAddFirst(linkedlist, "ghi");
    li_aux = LinkedListAddFirst(linkedlist, "z");
    
    printf("%i\n\n", LinkedListCompData(linkedlist, li_0->data, li_aux->data));
    
    // Remove o item 1
    LinkedListRemove(linkedlist, li_aux, 1);
    
    // Lista conteúdo da lista
    li_aux = LinkedListIterator(linkedlist);
    while((li_aux = LinkedListNext(linkedlist, li_aux)) != NULL)
        printf("%s\n", li_aux->data);
    
    printf("\n\n");
    //LinkedListClear(linkedlist);
    

    // Lista conteúdo da lista inversamente
    li_aux = LinkedListReverseIterator(linkedlist);
    while((li_aux = LinkedListNext(linkedlist, li_aux)) != NULL)
        printf("%s\n", li_aux->data);

    printf("\n\n");

    // Primeiro
    li_aux = LinkedListFirst(linkedlist);
    if(li_aux != NULL)
        printf("Primeiro=%s\n", li_aux->data);
    
    // Último
    li_aux = LinkedListLast(linkedlist);
    if(li_aux != NULL)
        printf("Ultimo=%s\n", li_aux->data);
    
    // Conta a quantidade de registros
    printf("count = %i", LinkedListCount(linkedlist));
}

int main(int argc, char** argv) {
    
    //intTest();
    strTest();
    return (EXIT_SUCCESS);
}
