#include <stdio.h>
#include <stdlib.h>

typedef struct child
{
	char let;
	int num;
} child;

int cmp(const void *a, const void *b)
{
	return ((child*)a)->let - ((child*)b)->let;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	child p[26];

	for (int i = 0; i < 26; ++i)
	{
		p[i].let = getc(f);
		p[i].num = i + 1;
	}
	qsort(p, 26, sizeof(child), cmp);
	for (int i = 0; i < 26; ++i)
		if (p[i].let - 'A' < i)
		{
			fprintf(q, "NO");
			return 0;
		}
	fprintf(q, "YES\n");
	for (int i = 0; i < 26; ++i)
		fprintf(q, "%d ", p[i].num);
	return 0;
}
