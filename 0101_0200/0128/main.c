#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	int p;
	struct cell *next;
} cell;

void add(cell **last, int k, int *m, int cur)
{
	(*last)->next = (cell*)malloc(sizeof(cell));
	*last = (*last)->next;
	(*last)->p = k;
	(*last)->next = NULL;
	m[k] = cur;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, x, y, a, b, *m;
    cell *last, *st;

    fscanf(f, "%d%d%d", &n, &x, &y);
    a = (x - 1) * n + y - 1;
    fscanf(f, "%d%d", &x, &y);
    b = (x - 1) * n + y - 1;
	m = (int*)malloc(n * n * sizeof(int));
	for (int i = 0; i < n * n; ++i)
		m[i] = -1;
	st = (cell*)malloc(sizeof(cell));
	st->next = NULL;
	st->p = a;
	m[a] = 0;
	last = st;
	while (m[b] < 0)
	{
		x = st->p / n, y = st->p % n;
		if (x >= 2 && y >= 1 && m[(x - 2) * n + y - 1] < 0)
			add(&last, (x - 2) * n + y - 1, m, m[st->p] + 1);
		if (x >= 1 && y >= 2 && m[(x - 1) * n + y - 2] < 0)
			add(&last, (x - 1) * n + y - 2, m, m[st->p] + 1);
		if (x < n - 2 && y < n - 1 && m[(x + 2) * n + y + 1] < 0)
			add(&last, (x + 2) * n + y + 1, m, m[st->p] + 1);
		if (x < n - 1 && y < n - 2 && m[(x + 1) * n + y + 2] < 0)
			add(&last, (x + 1) * n + y + 2, m, m[st->p] + 1);
		if (x >= 2 && y < n - 1 && m[(x - 2) * n + y + 1] < 0)
			add(&last, (x - 2) * n + y + 1, m, m[st->p] + 1);
		if (x >= 1 && y < n - 2 && m[(x - 1) * n + y + 2] < 0)
			add(&last, (x - 1) * n + y + 2, m, m[st->p] + 1);
		if (x < n - 2 && y >= 1 && m[(x + 2) * n + y - 1] < 0)
			add(&last, (x + 2) * n + y - 1, m, m[st->p] + 1);
		if (x < n - 1 && y >= 2 && m[(x + 1) * n + y - 2] < 0)
			add(&last, (x + 1) * n + y - 2, m, m[st->p] + 1);
		st = st->next;
	}
    fprintf(q, "%d", m[b]);
    return 0;
}
