#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	int p;
	struct cell *next;
} cell;

int add(cell **last, int k, int *l, int cur)
{
	if (l[k] == -2)
		return 1;
	if (l[k] > cur)
	{
		(*last)->next = (cell*)malloc(sizeof(cell));
		*last = (*last)->next;
		(*last)->p = k;
		(*last)->next = NULL;
		l[k] = cur;
	}
	return 0;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int h, m, n, *l, start, prod;
	cell *st, *last;
	char *s;

	fscanf(f, "%d%d%d", &h, &m, &n);
	l = (int*)malloc(sizeof(int) * (prod = h * m * n));
	s = (char*)malloc(n + 1);
	for (int i = 0; i < h * m; ++i)
	{
		fscanf(f, "%s", s);
		if (!*s)
			fscanf(f, "%s", s);
		for (int j = 0; j < n; ++j)
			if (s[j] == '.')
				l[i * n + j] = prod;
			else if (s[j] == 'o')
				l[i * n + j] = -1;
			else if (s[j] == '1')
				l[start = i * n + j] = 0;
			else
				l[i * n + j] = -2;
	}
	st = (cell*)malloc(sizeof(cell));
	st->next = NULL;
	st->p = start;
	last = st;
    while (!((st->p % n > 0 && add(&last, st->p - 1, l, l[st->p] + 1)) ||
		(st->p % n < n - 1 && add(&last, st->p + 1, l, l[st->p] + 1)) ||
		(st->p % (m * n) / n > 0 && add(&last, st->p - n, l, l[st->p] + 1)) ||
		(st->p % (m * n) / n < m - 1 && add(&last, st->p + n, l, l[st->p] + 1)) ||
		(st->p / (m * n) < h - 1 && add(&last, st->p + m * n, l, l[st->p] + 1))))
		st = st->next;
	fprintf(q, "%d", l[st->p] * 5 + 5);
    return 0;
}
