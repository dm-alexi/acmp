#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pers
{
	double res;
	char *name;
};

int cmp(const void *a, const void *b)
{
	if (((struct pers*)a)->res == ((struct pers*)b)->res)
		return 0;
	return ((struct pers*)a)->res > ((struct pers*)b)->res ? 1 : -1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 0;
	struct pers *p;
	char tmp[26];

	fscanf(f, "%d", &n);
	p = (struct pers*)malloc(sizeof(struct pers) * 20 * n);
	while (n--)
	{
		fscanf(f, "%d", &m);
		while (m--)
		{
			fscanf(f, "%lf %s", &p[k].res, tmp);
			p[k].name = (char*)malloc(strlen(tmp) + 1);
			strcpy(p[k++].name, tmp);
		}
	}
	qsort(p, k, sizeof(struct pers), cmp);
	fprintf(q, "%d\n", k);
	while (--k >= 0)
		fprintf(q, "%.2f %s\n", p[k].res, p[k].name);
	return 0;
}
