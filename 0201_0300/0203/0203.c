#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kmp(char *s, char *t)
{
	int n, m, *p;

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
		{
			free(p);
			return i - n + 1;
		}
	}
	free(p);
	return -1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[10001], t[20001];

	fscanf(f, "%s%s", s, t);
	strncat(t, t, strlen(s));
	fprintf(q, "%d", kmp(s, t));
	return 0;
}
