#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[10000][6], t[6];
	int n, k;

	fscanf(f, "%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		sprintf(s[i - 1], "%d", i);
	sprintf(t, "%d", k);
	qsort(s, n, 6, (int (*)(const void*, const void*))strcmp);
	fprintf(q, "%d", ((char*)bsearch(t, s, n, 6, (int (*)(const void*, const void*))strcmp) - (char*)s) / 6 + 1);
	return 0;
}
