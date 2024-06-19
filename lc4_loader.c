/************************************************************************/
/* File Name : lc4_loader.c		 										*/
/* Purpose   : This file implements the loader (ld) from PennSim		*/
/*             It will be called by main()								*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lc4_memory.h"

/* declarations of functions that must defined in lc4_loader.c */


// This function takes a 16-bit num and returns a shifted version of it (from Big to Little Endianness)
unsigned short int shifter(unsigned short int n) 
{
	unsigned short int a = n;
	unsigned short int b, c;

	b = a << 8;

	// printf("b = 0x%X\n", b);

	c = a >> 8;
	// printf("c = 0x%X\n", c);

	a = b | c;

	// printf("a = 0x%X\n", a);

	return a;
}


FILE* open_file(char* file_name)
{
	FILE* file_ptr = fopen(file_name, "rb");
	if (file_ptr == NULL)
	{
		printf("Failed to open file!");
	}

	return file_ptr ;
}


int parse_file (FILE* my_obj_file, row_of_memory** memory)
{
	// Create 3 vars to store header information
	unsigned short int header_type;
	unsigned short int address; // An array to hold scanned in value for address field
	unsigned short int n; // number of instructions/data values/chars of label
	
	// Iterature though the entire .obj file till EOF is reached
	while(!feof(my_obj_file))
	{
		// Read in header type
		int check = fread(&header_type, sizeof(unsigned short int), 1, my_obj_file);
		
		// Check if fread successfully reads in 1 unsigned short int (2 bytes)
		if (check == 1) // If 1 unsigned short int (4 hex #s) is read
		{
			if (header_type == 0xdeca || header_type == 0xdada) // If header type indicates it's ".CODE"
			{
				fread(&address, sizeof(unsigned short int), 1, my_obj_file);
				fread(&n, sizeof(unsigned short int), 1, my_obj_file);

				// Since .obj produced by PennSim uses Little Endianness, 
				// we need to shift it first to get the correct "n" (number of instructions/.Fill directives following .CODE and .ADDR)
				unsigned short int n_shifted = shifter(n);
				// Also need to shift address read in to get the address in Big Endianness (since we need to print out the address in Big Endianness)
				unsigned short int address_shifted = shifter(address);
				
				// In each iteration, read 1 * unsigned short ints from .obj,
				// which represents a 16 bit instruction (2 bytes)
				for (unsigned short int i = 0; i < n_shifted; i++)
				{
					// fread(&n, sizeof(unsigned short int), 1, my_obj_file);
					unsigned short int contents;
					fread(&contents, sizeof(unsigned short int), 1, my_obj_file);
					
					unsigned short int contents_shifted = shifter(contents);

					add_to_list(memory, address_shifted + i, contents_shifted);
				}
			}
			else if (header_type == 0xb7c3)
			{
				fread(&address, sizeof(unsigned short int), 1, my_obj_file);
				fread(&n, sizeof(unsigned short int), 1, my_obj_file);
				
				unsigned short int n_shifted = shifter(n);
				unsigned short int address_shifted = shifter(address);

				// Create a char array to hold chars of label
				char* label = malloc(sizeof(char)*n_shifted + 1); // Create a string to store label

				// Read in chars of label
				// Store them in label
				fread(label, sizeof(unsigned short int)/2, n_shifted, my_obj_file);

				// Pad a NULL to terminate the string
				label[n_shifted] = '\0';
				
				// Search the node by address_shifted
				row_of_memory* node_to_update = search_address(*memory, address_shifted);

				// printf("address_shifted: %x\n", address_shifted);

				if (node_to_update == NULL)
				{
					// since node with address_shifted doesn't exist
					// we need to first create a node to hold the label
					add_to_list(memory, address_shifted, 0x9999);

					// then we search for the node's address
					node_to_update = search_address(*memory, address_shifted);
					
					// update the newly created node's label 
					node_to_update->label = label; // store the address of memory block pointed to by label i node_to_update->label
					// Will need to free the memory block later in delete_list()
					// As for label, it is a local pointer variable, so it'll get destroyed once the frame is done.
					
				}
				else  // if the node with shifted address already exists
				{
					// Update node's label
					free(node_to_update->label); // Free the memory block pointed to by node_to_update->label first
					node_to_update->label = label; // Point node_to_update->label to a new memory block (string)
				}

			}
			else
			{
				printf("Sth other than 0xdeca, 0xdada, or 0xc3b7 is read. Error!\n");
				// fclose(my_obj_file);
			}
		}
		else // If we're reading the 2 extra zeros due to Little Endianness
		{
			// close the file
			// if there's error closing the file, delete list and return 2
			if (EOF == fclose(my_obj_file))
			{
				printf("Error closing file!\n");
				delete_list(memory);
				return 2;
			}
			// if there's no error closing the file, simply return 0
			return 0;
		}
	}

	if (EOF == fclose(my_obj_file))
	{
		printf("Error closing file!\n");
		delete_list(memory);
		return 2;
	}
	
	return 0 ;
}

