/************************************************************************/
/* File Name : lc4.c 													*/
/* Purpose   : This file contains the main() for this project			*/
/*             main() will call the loader and disassembler functions	*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lc4_memory.h"
#include "lc4_loader.h"
#include "lc4_disassembler.h"

/* program to mimic pennsim loader and disassemble object files */

int main (int argc, char** argv) {

	/**
	 * main() holds the linked list &
	 * only calls functions in other files
	 */

	/* step 1: create head pointer to linked list: memory 	*/
	row_of_memory* memory = NULL ;




// /////
// 	add_to_list(&memory, 0x0020, 0x1234);

// 	// printf("memory: %x\n", memory);
	
// 	add_to_list(&memory, 0x0000, 0x2345);

// 	// printf("memory: %x\n", memory);
// 	add_to_list(&memory, 0x0030, 0x3456);

// 	// printf("memory: %x\n", memory);
// 	add_to_list(&memory, 0x0010, 0x4567);

// 	// printf("memory: %x\n", memory);

	


// 	print_list(memory);

// 	row_of_memory* node_found = search_address(memory, 0x0030);
// 	printf("address found: %x\n", node_found->address);

// 	delete_list(&memory);

// 	print_list(memory);

	/* step 2: determine filename, then open it		*/
	/*   TODO: extract filename from argv, pass it to open_file() */
	if (argc != 2)
	{
		printf("CLA not given correctly! (Should be: \"./lc4 arg1\")\n");
		return -1;
	}

	// Now check if the file passed as CLA is an .obj file
	char* obj_cmp = ".obj"; 
	int	filename_len = strlen(argv[1]);
	char* filetype = &argv[1][filename_len - 4];
	
	if (strcmp(filetype, obj_cmp) != 0) // If it's not an .obj file
	{
		printf("The file passed in isn't an .obj file! Please pass in an .obj file. \n");
		return -2;
	}

	char* filename = argv[1];
	FILE* file_ptr = open_file(filename);


	/* step 3: call function: parse_file() in lc4_loader.c 	*/
	/*   TODO: call function & check for errors		*/
	parse_file(file_ptr, &memory);


	/* step 4: call function: reverse_assemble() in lc4_disassembler.c */
	/*   TODO: call function & check for errors		*/
	reverse_assemble(memory);


	/* step 5: call function: print_list() in lc4_memory.c 	*/
	/*   TODO: call function 				*/
	print_list(memory);


	/* step 6: call function: delete_list() in lc4_memory.c */
	/*   TODO: call function & check for errors		*/
	delete_list(&memory);


	/* only return 0 if everything works properly */
	return 0 ;
}
