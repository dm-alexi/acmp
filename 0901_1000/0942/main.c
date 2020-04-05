#include <stdio.h>

int main()
{
	FILE *q = fopen("output.txt", "w");

	putc('1', q);
	return 0;
}

