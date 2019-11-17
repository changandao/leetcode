//
//  main.cpp
//  ds
//
//  Created by Sam Wang on 15.11.19.
//  Copyright © 2019 Sam Wang. All rights reserved.
//

#include <iostream>
using namespace std;

/*This is a function problem.You only need to complete the function given below*/
/*Structure of the linked list node is as

}; */
// function inserts the data in front of the list

struct Node {
    int data;
    struct Node * next;
    Node(int x) {
      data = x;
      next = NULL;
    }
};
    
Node *insertAtBegining(Node *head, int newData) {
   // Your code here
   Node *newNode = new Node(newData);
   newNode->next = head;
   head = newNode;
   return head;
}
    
    
// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData)  {
   Node *newNode = new Node(newData);
   if(head == NULL)
   {
       head = newNode;
       return head;
   }
    else{
        Node *p = head;
    while(p->next!=NULL)
    p = p->next;
    p->next = newNode;
    return head;
    }
}
    

Node* deleteNode(Node *head,int data)
{
    Node *p = head;
    while(p->next!=NULL)
    {
        Node *p_next = p;
        if(p_next->data == data)
        {
            p->next = p_next->next;
            delete p_next;
        }
        else p = p->next;
    }
    return head;
}

Node* deleteNodeIndex(Node *head, int x)
{
    Node *p = head;
    Node *p_pre = head;
    int count=1;
    
    if(p == NULL)
    {
        return head;
    }
    
    if(x == 1)
    {
        head = p->next;
        return head;
    }
    while(p->next!=NULL && count != x)
    {
        p_pre = p;
        p = p->next;
        count ++;
    }
    
    p_pre->next = p->next;
    
    return head;
    
}


int getCount(Node* head){
    Node *p = head;
    int count{0};
    while (p!=NULL) {
        count ++;
        p = p->next;
    }
    return count;
}


void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}
  
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;
      
    // Insert 6. So linked list becomes 6->NULL
    head = insertAtEnd(head, 6);
      
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    head = insertAtBegining(head, 7);
      
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    head = insertAtBegining(head, 1);
      
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    head = insertAtEnd(head, 4);
      
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    //insertAfter(head->next, 8);
      
    cout<<"Created Linked list is: ";
    printList(head);
    cout<<endl;
    
    int length = getCount(head);
    cout<<"The length of the list is: ";
    cout<<length<<endl;
	int end;
	cin >> end;
    return 0;
}



