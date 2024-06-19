/************************************************************************/
/* File Name : lc4_disassembler.h 										*/
/* Purpose   : This function declares functions for lc4_dissembler.c	*/
/*      																*/
/*             															*/
/* Author(s) : tjf 														*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"

/*
 * declarations of functions that must defined in lc4_disassembler.c
 */



/**
 * translates the hex representation of arithmetic instructions
 * into their assembly equivalent in the given linked list.
 *
 * returns 0 upon success, and non-zero if an error occurs.
 */
int reverse_assemble (row_of_memory* memory) ;


/* Given a char array and 3 registers, 
 * fill out the array to make it a string representing 3 regs in arith asm instructions 
 */
int fill_reg_in_assembly_arith(char* assembly_string, 
						  unsigned short int rd, 
						  unsigned short int rs, 
						  unsigned short int rt);


/*
 * Given a char array and an imm5 number, edit it so it contains info about imm5 for imm5 instructions
 */
void fill_reg_in_assembly_imm5(char* assembly_string, short int imm5);