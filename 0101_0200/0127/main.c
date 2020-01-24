#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	int p;
	struct cell *next;
} cell;

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, a, b, *m, *s;
	cell *last, *st;

	fscanf(f, "%d", &n);
	m = (int*)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n * n; ++i)
		fscanf(f, "%d", m + i);
	fscanf(f, "%d%d", &a, &b);
	--a, --b;
	s = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		s[i] = -1;
	s[a] = 0;
	st = (cell*)malloc(sizeof(cell));
	st->next = NULL;
	st->p = a;
	last = st;
	while (s[b] < 0 && st)
	{
		for (int i = 0; i < n; ++i)
			if (m[st->p * n + i] && s[i] < 0)
			{
				last->next = (cell*)malloc(sizeof(cell));
				last = last->next;
				last->p = i;
				last->next = NULL;
				s[i] = s[st->p] + 1;
			}
			st = st->next;
	}
	fprintf(q, "%d", s[b]);
    return 0;
}
