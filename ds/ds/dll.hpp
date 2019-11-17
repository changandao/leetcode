//
//  dll.hpp
//  ds
//
//  Created by Sam Wang on 17.11.19.
//  Copyright © 2019 Sam Wang. All rights reserved.
//

#ifndef dll_hpp
#define dll_hpp

#include <stdio.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
};

/* Function to insert into a Doubly Linked List */
void addNode(Node *head, int pos, int data)
{
    Node *temp = new Node(data);
    Node *p = head;
    int count = 0;
    
    while(p->next != NULL && count !=pos)
    {
        count ++;
        p = p->next;
    }
    temp->next = p->next;
    
    p->next = temp;
    temp->prev = p;
    if (temp->next != NULL)
    temp->next->prev = temp;
    
}

void printList(struct Node* node)
{
    struct Node* last;
    printf("\nTraversal in forward direction \n");
    while (node ->next!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
        last = node;
    }
  
    printf("\nTraversal in reverse direction \n");
    while (last ->prev!= NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}
  
/* Driver program to test above functions*/




#endif /* dll_hpp */
