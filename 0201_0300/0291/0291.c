#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0, **p;
	char s[101];

	fscanf(f, "%d", &n);
	p = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i <= n; ++i)
	{
		fscanf(f, "%s", s);
		p[i] = (int*)calloc(26, sizeof(int));
		for (int j = 0; s[j]; ++j)
			++p[i][s[j] - 'a'];
	}
	for (int i = 0, j; i < n; ++i)
	{
		for (j = 0; j < 26; ++j)
			if (p[i][j] > p[n][j])
				break;
		k += (j == 26);
	}
	fprintf(q, "%d", k);
	return 0;
}
