/************************************************************************/
/* File Name : lc4_disassembler.c 										*/
/* Purpose   : This file implements the reverse assembler 				*/
/*             for LC4 assembly.  It will be called by main()			*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "lc4_memory.h"

int fill_reg_in_assembly_arith(char* assembly_string, 
						  unsigned short int rd, 
						  unsigned short int rs, 
						  unsigned short int rt)
{
	int x = (int) rd;
	int y = (int) rs;
	int z = (int) rt;


	assembly_string[3] = ' ';
	assembly_string[4] = 'R';
	assembly_string[5] = (char) (x + 48);
	assembly_string[6] = ',';
	assembly_string[7] = ' ';
	assembly_string[8] = 'R';
	assembly_string[9] = (char) (y + 48);
	assembly_string[10] = ',';
	assembly_string[11] = ' ';
	assembly_string[12] = 'R';
	assembly_string[13] =(char) (z + 48);
	assembly_string[14] = '\0';
	return 0;
}

void fill_reg_in_assembly_imm5(char* assembly_string, unsigned short int imm5)
{
	printf("imm5: %d\n", imm5);
	
	if (imm5 == 0)
	{
		assembly_string[13] = '0';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 1)
	{
		assembly_string[13] = '1';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 2)
	{
		assembly_string[13] = '2';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 3)
	{
		assembly_string[13] = '3';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 4)
	{
		assembly_string[13] = '4';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 5)
	{
		assembly_string[13] = '5';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 6)
	{
		assembly_string[13] = '6';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 7)
	{
		assembly_string[13] = '7';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 8)
	{
		assembly_string[13] = '8';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 9)
	{
		assembly_string[13] = '9';
		assembly_string[14] = '\0';
	}
	else if (imm5 == 10)
	{
		assembly_string[13] = '1';
		assembly_string[14] = '0';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 11)
	{
		assembly_string[13] = '1';
		assembly_string[14] = '1';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 12)
	{
		assembly_string[13] = '1';
		assembly_string[14] = '2';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 13)
	{
		assembly_string[13] = '1';
		assembly_string[14] = '3';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 14)
	{
		assembly_string[13] = '1';
		assembly_string[14] = '4';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 15)
	{
		assembly_string[13] = '1';
		assembly_string[14] = '5';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 31)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '1';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 30)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '2';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 29)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '3';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 28)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '4';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 27)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '5';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 26)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '6';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 25)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '7';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 24)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '8';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 23)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '9';
		assembly_string[15] = '\0';
	}
	else if (imm5 == 22)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '1';
		assembly_string[15] = '0';
		assembly_string[16] = '\0';
	}
	else if (imm5 == 21)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '1';
		assembly_string[15] = '1';
		assembly_string[16] = '\0';
	}
	else if (imm5 == 20)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '1';
		assembly_string[15] = '2';
		assembly_string[16] = '\0';
	}
	else if (imm5 == 19)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '1';
		assembly_string[15] = '3';
		assembly_string[16] = '\0';
	}
	else if (imm5 == 18)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '1';
		assembly_string[15] = '4';
		assembly_string[16] = '\0';
	}
	else if (imm5 == 17)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '1';
		assembly_string[15] = '5';
		assembly_string[16] = '\0';
	}
	else if (imm5 == 16)
	{
		assembly_string[13] = '-';
		assembly_string[14] = '1';
		assembly_string[15] = '6';
		assembly_string[16] = '\0';
	}
	else
	{
		printf("IMM5 is out of range. Some error must have happened! ");
	}
}

int reverse_assemble (row_of_memory* memory)
{


	// search by opcode to find there's any node whose opcode is equal to 0001
	row_of_memory* node = search_opcode(memory, 1);
	
	if (node == NULL)
	{
		print_list(memory);
		delete_list(&memory);
		return 0;
	}

	row_of_memory* cur = memory;
	while (cur != NULL && search_opcode(cur, 1) != NULL && cur->address < 0x2000)
	{
		node = search_opcode(cur, 1);

		// Inspect node returned from search; translate contents field into assembly instruction
	
		unsigned short int temp = (node->contents) & 0x0038; // bitwise AND to set digits other than node->contents[10:12] to 0
		unsigned short int subopcode = temp >> 3; // shift temp by 3 bits to the right to get subopcode

		// Similar technique to extract Rd
		temp = (node->contents) & 0x0E00;
		unsigned short int rd = temp >> 9;

		// Similar technique to extract Rs
		temp = (node->contents) & 0x01C0;
		unsigned short int rs = temp >> 6;


		// Similar technique to extract Rt
		temp = (node->contents) & 0x0007;
		unsigned short int rt = temp >> 0;

		
		// malloc a string to hold assembly
		char* assembly_string = malloc(sizeof(char) * 17);


		if (subopcode == 0) // This will be "ADD" instruction
		{

			// hardcore the first 3 chars of assembly
			assembly_string[0] = 'A';
			assembly_string[1] = 'D';
			assembly_string[2] = 'D';

			// call the helper function
			fill_reg_in_assembly_arith(assembly_string, rd, rs, rt);
			
			node->assembly = assembly_string;
			printf("node->assembly: %s\n", node->assembly);
			
		}
		else if (subopcode == 1)
		{
			assembly_string[0] = 'M';
			assembly_string[1] = 'U';
			assembly_string[2] = 'L';

			fill_reg_in_assembly_arith(assembly_string, rd, rs, rt);
			
			node->assembly = assembly_string;
			printf("node->assembly: %s\n", node->assembly);
		}
		else if (subopcode == 2)
		{
			assembly_string[0] = 'S';
			assembly_string[1] = 'U';
			assembly_string[2] = 'B';

			fill_reg_in_assembly_arith(assembly_string, rd, rs, rt);
			
			node->assembly = assembly_string;
			printf("node->assembly: %s\n", node->assembly);
		}
		else if (subopcode == 3)
		{
			assembly_string[0] = 'D';
			assembly_string[1] = 'I';
			assembly_string[2] = 'V';

			fill_reg_in_assembly_arith(assembly_string, rd, rs, rt);
			
			node->assembly = assembly_string;
			printf("node->assembly: %s\n", node->assembly);
		}
		else // ADD Rd Rs IMM5
		{
			assembly_string[0] = 'A';
			assembly_string[1] = 'D';
			assembly_string[2] = 'D';
			assembly_string[3] = ' ';
			assembly_string[4] = 'R';
			assembly_string[5] = rd + 48;
			assembly_string[6] = ',';
			assembly_string[7] = ' ';
			assembly_string[8] = 'R';
			assembly_string[9] = rs + 48;
			assembly_string[10] = ',';
			assembly_string[11] = ' ';
			assembly_string[12] = '#';

			unsigned short int imm5 = (node->contents) & 0x001F;

			fill_reg_in_assembly_imm5(assembly_string, imm5);
			node->assembly = assembly_string;
			printf("node->assembly: %s\n", node->assembly);
		}


		cur = cur->next;
	}


	return 0 ;
}





