#include <stddef.h>
#include <stdio.h>
#include "lc4_memory.h"

int add_to_list (row_of_memory** head,
		 short unsigned int address,
		 short unsigned int contents)
{
	
	/* allocate memory for a single node */
	row_of_memory* new_node = malloc(sizeof(row_of_memory));
	if (new_node == NULL)
	{
		printf("new_node = malloc has failed!\n");
		return -1;
	}
	/* populate fields in newly allocated node w/ address&contents (it's ok if CONTENTS=NULL) */
	new_node->address = address;
	new_node->contents = contents;
	new_node->label = NULL;
	new_node->assembly = NULL;


	/* if head==NULL, node created is the new head of the list! */
	if (*head == NULL)
	{
		*head = new_node;
		printf("*head == NULL: The list given is empty, so new node is added and head is updated \n");
		return 0;
	}

	// Case 1: if address is smaller than head->address, make the node the start of the list and glue the original head node to it
	if (address < (*head)->address)
	{
		new_node->next = *head;
		*head = new_node;
		printf("case 1 \n");
		return 0;
	}

	/* otherwise, traverse linked list until you reach an address before the address passed in */
	row_of_memory* temp = *head;

	while(temp->next != NULL)
	{
		// Case 2: If the address arguments falls in between two nodes' addresses, we find the spot to insert the node. 
		if (temp->address < address && address < (temp->next)->address)
		{
			/* insert node into the list - perform necessary "surgery" on this list */
			new_node->next = temp->next;
			temp->next = new_node;
			printf("case 2 \n");
			return 0;
		}

		temp = temp->next;
	}

	// If reaching here, it means temp->next is now NULL (end of list)
	// Case 3: add node to the end of list 
	temp->next = new_node;
	printf("case 3 \n");


	/* REMEMBER, .OBJ file can be out of ORDER!  Make certain to insert incoming node in order by address!! */


	/* return 0 for success, -1 if malloc fails */

	return 0 ;
}
