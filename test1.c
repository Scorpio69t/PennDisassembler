#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE* file_ptr = fopen(argv[1], "wb");
	if (file_ptr == NULL)
	{
		printf("fopen failed!\n");
	}
	unsigned short int arr[4] = {0xDADA, 0x0040, 0x0000};
	int check = fwrite(&arr[0], sizeof(unsigned short int), 4, file_ptr);
	if (check != 4)
	{
		printf("fwrite failed!\n");
	}
	fclose(file_ptr);
	return 0;
}