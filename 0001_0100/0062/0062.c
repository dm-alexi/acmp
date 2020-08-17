#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[3];

	fscanf(f, "%s", s);
	fprintf(q, (s[0] - 'A' + s[1] - '0') % 2 ? "BLACK" : "WHITE");
	return 0;
}
