#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"
#include "struct.h"

LinkedList * createLinkedList()
{
    LinkedList *ll = (LinkedList *) malloc(sizeof(LinkedList));
    
    ll->head = NULL;

    return ll;
}

void insertStart(LinkedList * list, void * data)
{
    LLnode * newNode = (LLnode*) malloc(sizeof(LLnode));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;   
}

void * removeStart(LinkedList * list)
{
    void * temp = NULL;
    
    LLnode * tempNode;
    if(list->head != NULL)
    {
        tempNode = list->head;
        temp = list->head->data;
        list->head = list->head->next;
        free(tempNode);
    }

    return temp;
}

void freeStruct(void * data)
{
    coordinates * coord = (coordinates*)data;
    free(coord);
}

void freeLinkedList(LinkedList* list) 
{
    LLnode *node, *nextNode;
    node = list->head;
    while(node != NULL){
        nextNode = node->next;
        freeStruct(node->data);
        free(node);
        node = nextNode;
    }
    free(list);
}