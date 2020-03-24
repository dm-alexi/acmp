#include <stdio.h>
#include <stdlib.h>

typedef struct web
{
	int line, h;
} web;

int cmp(const void *a, const void *b)
{
	return ((web*)b)->h - ((web*)a)->h;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k, m;
	web *w;

	fscanf(f, "%d%d", &k, &m);
	w = (web*)malloc(sizeof(web) * m);
	for (int i = 0; i < m; ++i)
		fscanf(f, "%d%d", &w[i].line, &w[i].h);
	qsort(w, m, sizeof(web), cmp);
	for (int i = 0; i < m; ++i)
		if (k == w[i].line)
			++k;
		else if (k == w[i].line + 1)
			--k;
	fprintf(q, "%d", k);
	return 0;
}
