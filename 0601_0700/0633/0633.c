#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[4][51];

	fscanf(f, "%[^\n] %[^\n] %[^\n] %[^\n]", s[3], s[0], s[1], s[2]);
	qsort(s, 3, sizeof(char[51]), (int (*)(const void*, const void*))strcmp);
	fprintf(q, "%s: %s, %s, %s", s[3], s[0], s[1], s[2]);
	return 0;
}
