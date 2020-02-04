#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
	int	a, b, dist;
} edge;

typedef struct heap
{
	edge *t;
	int num;
} heap;

void heapify(heap *h, int i)
{
	int left = 2 * i + 1, right = 2 * i + 2, small = i;

	if (left < h->num && h->t[left].dist < h->t[small].dist)
		small = left;
	if (right < h->num && h->t[right].dist < h->t[small].dist)
		small = right;
    if (small != i)
	{
		edge tmp = h->t[small];
		h->t[small] = h->t[i];
		h->t[i] = tmp;
		heapify(h, small);
	}
}

void put(heap *h, int a, int b, int d)
{
    int	k = h->num++;
    edge tmp;

    h->t[k].dist = d, h->t[k].a = a, h->t[k].b = b;
    while (k && h->t[k].dist < h->t[(k - 1) / 2].dist)
		tmp = h->t[k], h->t[k] = h->t[(k - 1) / 2], h->t[(k - 1) / 2] = tmp, k = (k - 1) / 2;
}

edge get(heap *h)
{
	edge tmp = h->t[0];

	h->t[0] = h->t[--h->num];
	heapify(h, 0);
	return tmp;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 1, len = 0, l;
	heap h = {NULL, 0};
	char *s;
	edge tmp;

	fscanf(f, "%d%d", &n, &m);
	if (n > 1)
	{
		s = (char*)malloc(n);
		for (int i = 0; i < n; ++i)
			s[i] = i;
		h.t = (edge*)malloc(sizeof(edge) * m);
		for (int i = 0, a, b, d; i < m; ++i)
		{
			fscanf(f, "%d%d%d", &a, &b, &d);
			if (a != b)
				put(&h, a - 1, b - 1, d);
		}
		tmp = get(&h);
		s[tmp.b] = s[tmp.a];
		len = tmp.dist;
		while (k < n - 1)
		{
			tmp = get(&h);
			if ((s[tmp.a] != s[tmp.b]))
			{
				len += tmp.dist;
				l = s[tmp.b];
				for (int i = 0; i < n; ++i)
					if (s[i] == l)
						s[i] = s[tmp.a];
				++k;
			}
		}
	}
	fprintf(q, "%d", len);
    return 0;
}
