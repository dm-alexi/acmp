#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[81];

	fscanf(f, "%d%s", &n, s);
	s[n - 1] = '\0';
	fprintf(q, "%s%s", s, s + n);
	return 0;
}

