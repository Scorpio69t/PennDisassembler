#########################################################
#  file name   : Makefile                               #
#  author      : Thomas Farmer                          #
#  description : Makefile to automate compiling         #
#                and linking                            #
#########################################################
#
#

all: lc4

lc4: lc4.c lc4_disassembler.h lc4_disassembler.o lc4_loader.h lc4_loader.o lc4_memory.h lc4_memory.o 
	clang -Wall -g lc4.c lc4_disassembler.c lc4_loader.c lc4_memory.c -o lc4

lc4_disassembler.o: lc4_disassembler.c
	clang -c lc4_disassembler.c

lc4_loader.o: lc4_loader.c
	clang -c lc4_loader.c

lc4_memory.o: lc4_memory.c
	clang -c lc4_memory.c



clean:
	rm -rf *.o

clobber: clean
	rm -rf lc4
