#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char t[50001], s[50001];
	int n, m, *p;

	fscanf(f, "%s%s", t, s);
	n = strlen(s), m = strlen(t);
	p = (int*)malloc(sizeof(int) * n);
	p[0] = 0;
	for (int i = 1, k = 0; i < n; ++i)
	{
		while (k > 0 && s[i] != s[k])
			k = p[k - 1];
		if (s[i] == s[k])
			++k;
		p[i] = k;
	}
	for (int i = 0, k = 0; i < m; ++i)
	{
		while (k > 0 && s[k] != t[i])
			k = p[k - 1];
		if (s[k] == t[i])
			++k;
		if (k == n)
			fprintf(q, "%d ", i - n + 1);
	}
	return 0;
}
