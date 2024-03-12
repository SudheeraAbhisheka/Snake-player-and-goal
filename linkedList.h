#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode
{
    void * data;
    struct LinkedListNode * next;
}LLnode;

typedef struct
{
    LLnode * head;
}LinkedList;

typedef void (*FunPtr)(void * data);

LinkedList * createLinkedList();
void insertStart(LinkedList * list, void * data);
void * removeStart(LinkedList * list);
void freeLinkedList(LinkedList* list);

#endif