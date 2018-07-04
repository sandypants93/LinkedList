#include <LinkedList.h>
#include <stdio.h>
#include <stdlib.h>


void linkedListNodeInit(struct LinkedListNode *node, void *data)
{
    /**************************************************************************
     * linkedListNodeInit is the initializing function for the LinkedListNode
     * struct.
     *************************************************************************/
    node = calloc(1, sizeof(struct LinkedListNode));
    if (node == NULL)
    {
        return;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return;
}

void linkedListInit(struct LinkedList *list, deleteFunction deleteNode)
{
    /**************************************************************************
     * linkedListInit is the initializing function for the LinkedList struct.
     *************************************************************************/
    list = calloc(1, sizeof(struct LinkedList));
    if (list == NULL)
    {
        perror("calloc")
        return;
    }
    linkedListNodeInit(list->sentry, NULL);
    if (list->sentry == NULL)
    {
        return;
    }
    list->deleteNode = deleteNode;
    list->size = 0;
    return;
}

int linkedListPrepend(struct LinkedList *list, void *data)
{
    /**************************************************************************
     * linkedListPrepend will initialize a new node and place it at the
     * front of the list.
     * 
     * returns 0 on success and -1 on error.
     *************************************************************************/
    if (list == NULL)
    {
        fprintf("linkedListPrepend: uninitialized LinkedList\n")
        return -1;
    }
    struct LinkedListNode *newNode;
    linkedListNodeInit(newNode, data);
    if (newNode == NULL)
    {
        return -1;
    }
    if (!(list->size))
    {
        list->sentry->next = newNode;
        list->sentry->prev = newNode;
        newNode->next = list->sentry;
        newNode->prev = list->sentry;
    } 
    else 
    {
        struct LinkedListNode *oldHead;
        oldHead = list->sentry->next;
        list->sentry->next = newNode;
        oldHead->prev = newNode;
        newNode->next = oldHead;
        newNode->prev = list->sentry;
    }
    list->size += 1;
    return 0;
}

int linkedListAppend(struct LinkedList *list, void *data);

void *linkedListPopHead(struct LinkedList *list);

void *linkedListPopTail(struct LinkedList *list);