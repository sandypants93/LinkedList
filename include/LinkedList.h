#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef void (*deleteFunction)(void *data);

struct LinkedListNode {
    void *data;
    struct LinkedListNode *next; 
    struct LinkedListNode *prev;
};

struct LinkedList {
    struct LinkedListNode *sentry;
    deleteFunction deleteNode;
    int *size;
};

void linkedListNodeInit(struct LinkedListNode *node, void *data);

void linkedListInit(struct LinkedList *list, deleteFunction deleteNode);

int linkedListPrepend(struct LinkedList *list, void *data);

int linkedListAppend(struct LinkedList *list, void *data);

void *linkedListPopHead(struct LinkedList *list);

void *linkedListPopTail(struct LinkedList *list);

#define linkedListSize(list) ((list)->size)

#define linkedListHead(list) ((list)->sentry->next)

#define linkedListTail(list) ((list)->sentry->prev)

#endif