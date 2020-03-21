#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	char c = *(char*)a, d = *(char*)b;

	return islower(c) && isupper(d) ? -1 : isupper(c) && islower(d) ? 1 : c - d;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 0, l = 0;
	char *s1, *s2, *a;

	fscanf(f, "%d%d", &n, &m);
	s1 = (char*)malloc(n * m + 1);
	s2 = (char*)malloc(n * m + 1);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%s", s1 + i * m);
	for (int i = 0; i < n * m; ++i)
		k += (s1[i] != '.');
	a = (char*)malloc(k + 1);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%s", s2 + i * m);
	for (int i = 0; i < n * m; ++i)
		if (s1[i] != '.' && s1[i] != s2[i])
			a[l++] = s1[i];
	qsort(a, l, 1, cmp);
	a[l] = '\0';
	fprintf(q, "%d", l);
	if (l)
		fprintf(q, "\n%s", a);
	return 0;
}
