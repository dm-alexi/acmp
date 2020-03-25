#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[30001];
	int a = 1, b = 0, c, n;

	fscanf(f, "%s", s);
	n = strlen(s);
	while ((c = a + b) <= n)
		b = a, a = c, putc(s[c - 1], q);
	return 0;
}
