#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char c;

	while ((c = getc(f)) == '1');
	fprintf(q, c == '0' ? "NO" : "YES");
	return 0;
}
