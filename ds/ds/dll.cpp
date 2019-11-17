//
//  dll.cpp
//  ds
//
//  Created by Sam Wang on 17.11.19.
//  Copyright © 2019 Sam Wang. All rights reserved.
//

#include "dll.hpp"

int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	push(&head, 7);

	push(&head, 1);

	push(&head, 4);

	// Insert 8, before 1. So linked list becomes 4->8->1->7->NULL
	insertBefore(&head, head->next, 8);

	printf("Created DLL is: ");
	printList(head);

	getchar();
	return 0;
}