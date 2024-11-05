#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList{
    struct MyLinkedList * next;
    int val;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    return (MyLinkedList*) malloc(sizeof(MyLinkedList));
}

MyLinkedList* create_node(int val)
{
    MyLinkedList * node = myLinkedListCreate();
    node->val=val;
    return node;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList * temp = obj;
    for (int i = 0; i < index-1; i++)
    {
        temp=temp->next;
    }
    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList * node =create_node(val);
    node->next=obj;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList * temp = obj;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    MyLinkedList * node =create_node(val);
    temp->next=node;
    node->next=NULL;
}

int find_length(MyLinkedList* obj)
{
    int len=0;
    MyLinkedList * temp = obj;
    while (temp->next!=NULL)
    {
        len++;
        temp=temp->next;
    }
    return len;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index>find_length(obj))
    {
        return;
    }
    MyLinkedList * node =create_node(val);
    MyLinkedList * temp = obj;
    for (int i = 0; i < index-1; i++)
    {
        temp=temp->next;
    }
    node->next=temp->next;
    temp->next=node;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index>find_length(obj))
    {
        return;
    }
    MyLinkedList * temp = obj;
    for (int i = 0; i < index-1; i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

void myLinkedListFree(MyLinkedList* obj) {
    
}