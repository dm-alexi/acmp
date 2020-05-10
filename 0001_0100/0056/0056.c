#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int found(char **base, char *s, int left, int right)
{
	if (left > right)
		return 0;
	int k = strcmp(base[(left + right) / 2], s);
	return !k ? 1 : k < 0 ? found(base, s, (left + right) / 2 + 1, right) : found(base, s, left, (left + right) / 2 - 1);
}

int comp(const char **s, const char **t)
{
	return strcmp(*s, *t);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 0, h = 0;
	char **p, **r, **t, s[21];

	fscanf(f, "%d", &n);
	if (n)
	{
		p = (char**)malloc(sizeof(char*) * n);
		for (int i = 0; i < n; ++i)
		{
			fscanf(f, "%s", s);
			p[i] = (char*)malloc(strlen(s) + 1);
			strcpy(p[i], s);
		}
		qsort(p, n, sizeof(char*), (int(*)(const void *, const void *))comp);
	}
	fscanf(f, "%d", &m);
	if (m)
	{
		r = (char**)malloc(sizeof(char*) * m);
		t = (char**)malloc(sizeof(char*) * m);
		for (; k + h < m;)
		{
			fscanf(f, "%s", s);
			if (found(p, s, 0, n - 1))
			{
				r[k] = (char*)malloc(strlen(s) + 1);
				strcpy(r[k++], s);
			}
			else
			{
				t[h] = (char*)malloc(strlen(s) + 1);
				strcpy(t[h++], s);
			}
		}
		qsort(r, k, sizeof(char*), (int(*)(const void *, const void *))comp);
		qsort(t, h, sizeof(char*), (int(*)(const void *, const void *))comp);
	}
	fprintf(q, "Friends: ");
	for (int i = 0; i < n; ++i)
		fprintf(q, i == n - 1 ? "%s" : "%s, ", p[i]);
	fprintf(q, "\nMutual Friends: ");
	for (int i = 0; i < k; ++i)
		fprintf(q, i == k - 1 ? "%s" : "%s, ", r[i]);
	fprintf(q, "\nAlso Friend of: ");
	for (int i = 0; i < h; ++i)
		fprintf(q, i == h - 1 ? "%s" : "%s, ", t[i]);
	return 0;
}
