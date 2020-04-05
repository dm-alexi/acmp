#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1251

int longread(FILE *f, int *a)
{
	char s[2502], *t;
	int j = N - 1;

	fscanf(f, "%s", s);
	for (t = s + strlen(s) - 4; s < t; t -= 4)
		a[j--] = atoi(t), *t = '\0';
	a[j] = atoi(s);
	return j;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a[N] = {0}, b[N] = {0}, d[N] = {0}, al, bl, k;

	al = longread(f, a);
	bl = longread(f, b);
	for (int i = N - 1; i >= al; --i)
		for (int j = N - 1; j >= bl; --j)
			if ((d[j - N + 1 + i] += a[i] * b[j]) >= 10000)
				d[j - N + i] += d[j - N + 1 + i] / 10000, d[j - N + 1 + i] %= 10000;
	for (k = 0; !d[k] && k < N - 1; ++k);
	fprintf(q, "%d", d[k]);
	while (++k < N)
		fprintf(q, "%04d", d[k]);
	return 0;
}
