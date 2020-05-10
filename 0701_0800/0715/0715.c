#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 0;
	char *s1, *s2;

	fscanf(f, "%d%d", &n, &m);
	s1 = (char*)malloc(n * m + 1);
	s2 = (char*)malloc(n * m + 1);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%s", s1 + i * m);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%s", s2 + i * m);
	while (*s1)
		k += (*s1++ == *s2++);
	fprintf(q, "%d", k);
	return 0;
}
