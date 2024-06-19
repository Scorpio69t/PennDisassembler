/************************************************************************/
/* File Name : lc4_memory.c		 										*/
/* Purpose   : This file implements the linked_list helper functions	*/
/* 			   to manage the LC4 memory									*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lc4_memory.h"

// add_to_list works!
/*
 * adds a new node to linked list pointed to by head - MUST keep list in order by address
 */
int add_to_list (row_of_memory** head,
		 short unsigned int address,
		 short unsigned int contents)
{
	
	/* allocate memory for a single node */
	row_of_memory* new_node = NULL;
	new_node = malloc(sizeof(row_of_memory));
	if (new_node == NULL)
	{
		printf("new_node = malloc has failed!\n");
		return -1;
	}
	/* populate fields in newly allocated node w/ address&contents (it's ok if CONTENTS=NULL) */
	new_node->address = address;

	// printf("new_node->address: %x\n", new_node->address);

	new_node->contents = contents;
	new_node->label = NULL;
	new_node->assembly = NULL;
	new_node->next = NULL;


	// printf("*head: %x\n", *head);

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
		// printf("case 1 \n");
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
			// printf("case 2 \n");
			return 0;
		}

		temp = temp->next;
	}

	// If reaching here, it means temp->next is now NULL (end of list)
	// Case 3: add node to the end of list 
	temp->next = new_node;
	// printf("case 3 \n");


	/* REMEMBER, .OBJ file can be out of ORDER!  Make certain to insert incoming node in order by address!! */


	/* return 0 for success, -1 if malloc fails */

	return 0 ;
}


// search_address works!
/*
 * search linked list by address field, returns node if found
 */
row_of_memory* search_address (row_of_memory* head,
			       short unsigned int address )
{
	/* traverse linked list, searching each node for "address"  */
	row_of_memory* temp = head;


	while (temp != NULL)
	{
		// printf("temp: %x\n", temp);
		
		
		// If the address is found, return the address of the node storing the address
		if (temp->address == address)
		{
			// printf("temp->address == address! %x\n", temp->address);
			return temp;
		}

		// If the address isn't found, advance the pointer
		temp = temp->next;
	}

	printf("address not found!\n");
	return temp;

	
	/* return pointer to node in the list if item is found */


	/* return NULL if list is empty or if "address" isn't found */

}


/*
 * search linked list by opcode field, returns node if found
 */
row_of_memory* search_opcode  (row_of_memory* head,
				      short unsigned int opcode  ) 
{
	/* traverse linked list until node is found with matching opcode
	   AND "assembly" field of node is empty */

	/* return pointer to node in the list if item is found */

	/* return NULL if list is empty or if no matching nodes */

	row_of_memory* cur = NULL;
	cur = head;

	while (cur != NULL)
	{
		unsigned short int temp = cur->contents >> 12; 
		if (temp == opcode && cur->assembly == NULL)
		{
			return cur;
		} 
		cur = cur->next;
	}
	
	return NULL ;
}


void print_list (row_of_memory* head )
{
	/* make sure head isn't NULL */
	if (head == NULL)
	{
		printf("head is NULL!\n");
		return;
	}

	row_of_memory* temp = head;

	/* print out a header */
		char* lab = "<Label>";
		char* add = "<Address>";
		char* con = "<Contents>";
		char* ass = "<Assembly Instructions>";

		printf("%-20s%-20s%-20s%-20s\n", lab, add, con, ass);


	/* traverse linked list, print contents of each node */
	while (temp != NULL)
	{
		// print the label field
		printf("%-20s%-20.4x%-20.4x%-20s\n", temp->label, temp->address, temp->contents, temp->assembly);

		printf("\n");
		temp = temp->next;
		
		
	}

	return ;
}


// not sure if delete_list works because valgrind is weird
/*
 * delete entire linked list
 */
int delete_list    (row_of_memory** head )
{
	/* delete entire list node by node */
	/* if no errors, set head = NULL upon deletion */
	row_of_memory* cur = NULL;
	row_of_memory* next = NULL;
	cur = *head;
	next = *head;


	while (cur != NULL)
	{
		next = cur->next; 
		// printf("deleting cur->address: %x", cur->address); 
		if (cur->label != NULL)
		{
			free(cur->label);
		}
		if (cur->assembly != NULL)
		{
			free(cur->assembly);
		}
		free(cur);
		// printf("free(cur)!!!\n");
		cur = next;
	}

	// After deleting all nodes, update head to NULL
	*head = NULL;

	/* return 0 if no error, -1 for any errors that may arise */
	return 0 ;
}
