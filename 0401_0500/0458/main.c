#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, *p;
	char str[201], t[201], *s = str;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i), --p[i];
	fscanf(f, "%s", str);
	m = strlen(str);
	for (int i = 0; i < n; ++i)
		for (int j = p[i]; j < m; j += n)
			t[j] = *s++;
	t[m] = '\0';
	fprintf(q, t);
	return 0;
}
