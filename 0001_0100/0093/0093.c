#include <stdio.h>
#include <string.h>

int comp(char *s, char *t)
{
	int k = 0, n = strlen(s);
	if (n != strlen(t))
		return 0;
	for (int i = 0; i < n && k < 2; ++i)
		k += (s[i] != t[i]);
	return k == 1 ? 1 : 0;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, i, j;
	char s[30][31], t[30][31];

	fscanf(f, "%d", &n);
	for (i = 0; i < n; ++i)
		fscanf(f, "%s", s[i]);
	fscanf(f, "%d", &m);
	for (i = 0; i < m; ++i)
		fscanf(f, "%s", t[i]);
	for (i = 0; i < n; ++i)
	{
		int p = 0;
		for (j = 0; j < m; ++j)
			p += comp(s[i], t[j]);
		fprintf(q, "%d ", p);
	}
	return 0;
}
