#include <stdio.h>

#include "LinkedList.h"

//
// Add any data to list
//
struct llnode *LinkedListAdd(struct linkedlist *linkedlist, struct llnode *node, void *data) {
    struct llnode *nw = (struct llnode *) malloc(sizeof (struct llnode));
    // nw == NULL, malloc failed
    if (nw == NULL) {
        perror("Not enough memory");
        exit(EXIT_FAILURE);
    }
    
    nw->data = data;
    nw->size = LinkedListGetTypeSize(linkedlist->data_type, data);
    nw->prev = node;
    
    if (node->next != NULL) {
        nw->next = node->next;
        node->next->prev = nw;
    }

    node->next = nw;

    // Increase counter
    linkedlist->size++;

    return nw;
}

//
// Add as first node list
//
struct llnode *LinkedListAddFirst(struct linkedlist *linkedlist, void *data) {
    if (linkedlist == NULL)
        return NULL;
    return LinkedListAdd(linkedlist, linkedlist->head, data);
}

//
// Add as last node list
//
struct llnode *LinkedListAddLast(struct linkedlist *linkedlist, void *data) {
    if (linkedlist == NULL)
        return NULL;
    return LinkedListAdd(linkedlist, linkedlist->tail->prev, data);
}

//
// Remove node from list.
//   Note: If purge = 0, is recommended to use free() to deallocate node after 
//         use it.
//
void LinkedListRemove(struct linkedlist *linkedlist, struct llnode *node, int purge) {
    if (!LinkedListIsEmpty(linkedlist)) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        if (purge) free(node);
        linkedlist->size--;
    }
}

//
// Get next node from list
//
struct llnode *LinkedListNext(const struct linkedlist *linkedlist, const struct llnode *ll) {
    if (linkedlist->ll_rev_iterator)
        return (ll->prev == linkedlist->head ? NULL : ll->prev);
    else
        return (ll->next == linkedlist->tail ? NULL : ll->next);
}

//
// Create a new list
//
struct linkedlist *LinkedListCreate(enum lltype data_type) {
    struct linkedlist *linkedlist = (struct linkedlist *) malloc(sizeof (struct linkedlist));
    struct llnode *head = (struct llnode *) malloc(sizeof (struct llnode));
    struct llnode *tail = (struct llnode *) malloc(sizeof (struct llnode));

    head->data = NULL;
    head->size = 0;
    head->next = NULL;
    head->prev = NULL;
    tail->data = NULL;
    tail->size = 0;
    tail->next = NULL;
    tail->prev = NULL;

    head->next = tail;
    tail->prev = head;

    linkedlist->head = head;
    linkedlist->tail = tail;
    linkedlist->data_type = data_type;
    linkedlist->ll_rev_iterator = 0;
    linkedlist->size = 0;

    return linkedlist;
}

//
// Count list nodes
//
int LinkedListCount(const struct linkedlist *linkedlist) {
    int c = 0;
    if (linkedlist != NULL)
        c = linkedlist->size;
    return c;
}

//
// Verify if list is empty
//
int LinkedListIsEmpty(const struct linkedlist *linkedlist) {
    if (linkedlist == NULL)
        return 1;
    return (linkedlist->head->next == linkedlist->tail ? 1 : 0);
}

//
// Get a list iterator. Must be invoked before 'LinkedListNext' function.
//
struct llnode *LinkedListIterator(struct linkedlist *linkedlist) {
    if (linkedlist == NULL)
        return NULL;
    linkedlist->ll_rev_iterator = 0;
    return linkedlist->head;
}

//
// Get a reverse list iterator. Must be invoked before 'LinkedListNext' function.
//
struct llnode *LinkedListReverseIterator(struct linkedlist *linkedlist) {
    if (linkedlist == NULL)
        return NULL;
    linkedlist->ll_rev_iterator = 1;
    return linkedlist->tail;
}

//
// Return the first node of the list
//
struct llnode *LinkedListFirst(const struct linkedlist *linkedlist) {
    if (LinkedListIsEmpty(linkedlist))
        return NULL;
    return linkedlist->head->next;
}

//
// Return the last node of the list
//
struct llnode *LinkedListLast(const struct linkedlist *linkedlist) {
    if (LinkedListIsEmpty(linkedlist))
        return NULL;
    return linkedlist->tail->prev;
}

//
// Return a size data added to list
//
size_t LinkedListGetTypeSize(enum lltype data_type, void *data) {
    size_t s;
    switch (data_type) {
        case T_DOUBLE:
            s = sizeof(double);
            break;
        case T_FLOAT:
            s = sizeof(float);
            break;
        case T_INT:
            s = sizeof(int);
            break;
        case T_LDOUBLE:
            s = sizeof(long double);
            break;
        case T_UINT:
            s = sizeof(unsigned int);
            break;
        case T_STR:
            s = (sizeof(char) * strlen((char *)data));
            break;
        default: // T_CHAR
            s = sizeof(char);
            break;
    }
    
    return s;
}

//
// Compare if data1 is EQUAL data2
//
int LinkedListEQData(const struct linkedlist *linkedlist, void *data1, void *data2) {
    switch (linkedlist->data_type) {
        case T_DOUBLE:
            return ((double *)data1 == (double *)data2);
        case T_FLOAT:
            return ((float *)data1 == (float *)data2);
        case T_INT:
            return ((int *)data1 == (int *)data2);
        case T_LDOUBLE:
            return ((long double *)data1 == (long double *)data2);
        case T_UINT:
            return ((unsigned int *)data1 == (unsigned int *)data2);
        case T_STR: 
            return (strcmp(((char *)data1), ((char *)data2)) == 0);
        default: // T_CHAR
            return ((char *)data1 == (char *)data2);
    }
}

//
// Compare if data1 is GREATER THAN data2
//
int LinkedListGTData(const struct linkedlist *linkedlist, void *data1, void *data2) {
    switch (linkedlist->data_type) {
        case T_DOUBLE:
            return ((double *)data1 > (double *)data2);
        case T_FLOAT:
            return ((float *)data1 > (float *)data2);
        case T_INT:
            return ((int *)data1 > (int *)data2);
        case T_LDOUBLE:
            return ((long double *)data1 > (long double *)data2);
        case T_UINT:
            return ((unsigned int *)data1 > (unsigned int *)data2);
        case T_STR: 
            return (strcmp(((char *)data1), ((char *)data2)) > 0);
        default: // T_CHAR
            return ((char *)data1 > (char *)data2);
    }
}

//
// Compare if data1 is LESS THAN data2
//
int LinkedListLTData(const struct linkedlist *linkedlist, void *data1, void *data2) {
    switch (linkedlist->data_type) {
        case T_DOUBLE:
            return ((double *)data1 < (double *)data2);
        case T_FLOAT:
            return ((float *)data1 < (float *)data2);
        case T_INT:
            return ((int *)data1 < (int *)data2);
        case T_LDOUBLE:
            return ((long double *)data1 < (long double *)data2);
        case T_UINT:
            return ((unsigned int *)data1 < (unsigned int *)data2);
        case T_STR: 
            return (strcmp(((char *)data1), ((char *)data2)) < 0);
        default: // T_CHAR
            return ((char *)data1 < (char *)data2);
    }
}

//
// Compare data1 and data2:
//    (data1 < data2)  = -1
//    (data1 == data2) =  0 
//    (data1 > data2)  =  1
//
int LinkedListCompData(const struct linkedlist *linkedlist, void *data1, void *data2) {
    int ret = -2;
    
    // data1 < data2, return -1
    if (LinkedListLTData(linkedlist, data1, data2))
        ret = -1;
    // data1 == data2, return 0
    else if(LinkedListEQData(linkedlist, data1, data2))
        ret = 0;
    // data1 > data2, return 1
    else if(LinkedListGTData(linkedlist, data1, data2))
        ret = 1;
    
    return ret;
}

//
// Clear a list
//
void LinkedListClear(struct linkedlist *linkedlist) {
    if (linkedlist == NULL)
        return;
    
    // free llnode from memory
    struct llnode *node = linkedlist->head;
    if(node->next != linkedlist->tail) {
        LinkedListNodeFree(linkedlist, node->next);
    }
    
    // empty list
    linkedlist->head->next = linkedlist->tail;
    linkedlist->tail->prev = linkedlist->head;
}

//
// Freed a node and your subsequent nodes
//
void LinkedListNodeFree(struct linkedlist *linkedlist, struct llnode *node) {
    if(node == linkedlist->tail)
        return;
    LinkedListNodeFree(linkedlist, node->next);
    free(node);
}