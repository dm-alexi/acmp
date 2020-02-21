#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[51];
	int len;
	int rating;
} song;

int cmp(const void *a, const void *b)
{
	return strcmp((*(song**)a)->name, (*(song**)b)->name);
}

int cmp2(const void *a, const void *b)
{
	return strcmp((char*)a, (*(song**)b)->name);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, m, *p;
	song **init, **fin, **playlist;
	char s[51];

	fscanf(f, "%d", &n);
	init = (song**)malloc(sizeof(song*) * n);
	fin = (song**)malloc(sizeof(song*) * n);
	for (int i = 0; i < n; ++i)
	{
		init[i] = fin[i] = (song*)malloc(sizeof(song));
		fscanf(f, "%s %d", init[i]->name, &init[i]->len);
		init[i]->rating = 0;
	}
	qsort(fin, n, sizeof(song*), cmp);
	fscanf(f, "%d%d", &m, &k);
	playlist = (song**)malloc(sizeof(song*) * m);
	for (int i = 0; i < m; ++i)
	{
		fscanf(f, "%s", s);
		playlist[i] = *((song**)bsearch(s, fin, n, sizeof(song*), cmp2));
	}
	p = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; ++i)
		fscanf(f, "%d", p + i);
	for (int i = 0, len = 0, j = 0; i < m; ++i)
		if (j == k || len + playlist[i]->len <= p[j])
			++(playlist[i]->rating), len += playlist[i]->len;
		else
			--(playlist[i]->rating), len = p[j++];
	for (int i = 0; i < n; ++i)
		fprintf(q, "%d ", init[i]->rating);
	return 0;
}
