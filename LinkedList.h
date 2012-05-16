/* 
 * File:   LinkedList.h
 * Author: gontijo
 *
 * Created on May 8, 2012, 7:56 PM
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <linux/types.h>
#include <stdlib.h>
#include <string.h>

typedef __kernel_size_t size_t;

enum lltype {
    T_CHAR,
    T_DOUBLE,
    T_FLOAT,
    T_INT,
    T_LDOUBLE,
    T_UINT,
    T_STR
};

struct llnode {
    void *data;
    size_t size;
    struct llnode *next;
    struct llnode *prev;
};

struct linkedlist {
    struct llnode *head;
    struct llnode *tail;
    enum lltype data_type;
    int ll_rev_iterator;
    int size;
};

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus    
}
#endif

struct llnode *LinkedListAdd(struct linkedlist *linkedlist, struct llnode *node, void *data);
struct llnode *LinkedListAddFirst(struct linkedlist *linkedlist, void *data);
struct llnode *LinkedListAddLast(struct linkedlist *linkedlist, void *data);
void LinkedListRemove(struct linkedlist *linkedlist, struct llnode *node, int purge);
struct llnode *LinkedListIterator(struct linkedlist *linkedlist);
struct llnode *LinkedListReverseIterator(struct linkedlist *linkedlist);
struct llnode *LinkedListNext(const struct linkedlist *linkedlist, const struct llnode *ll);
struct linkedlist *LinkedListCreate(enum lltype data_type);
int LinkedListCount(const struct linkedlist *linkedlist);
int LinkedListIsEmpty(const struct linkedlist *linkedlist);
struct llnode *LinkedListFirst(const struct linkedlist *linkedlist);
struct llnode *LinkedListLast(const struct linkedlist *linkedlist);
int LinkedListEQData(const struct linkedlist *linkedlist, void *data1, void *data2);
int LinkedListGTData(const struct linkedlist *linkedlist, void *data1, void *data2);
int LinkedListLTData(const struct linkedlist *linkedlist, void *data1, void *data2);
int LinkedListCompData(const struct linkedlist *linkedlist, void *data1, void *data2);
size_t  LinkedListGetTypeSize(enum lltype, void *data);
void LinkedListClear(struct linkedlist *linkedlist);
void LinkedListNodeFree(struct linkedlist *linkedlist, struct llnode *node);

#endif	/* LINKEDLIST_H */

