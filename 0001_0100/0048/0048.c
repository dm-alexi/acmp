#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[5002];
	int i;

	fscanf(f, "%s", s);
	putc('1', q);
	for (i = 0; s[i]; ++i);
	while (s[--i] == '0')
		putc('0', q);
	return 0;
}
