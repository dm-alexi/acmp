#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
	int	ind, dist;
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

void put(heap *h, int i, int d)
{
    int	k = h->num++;
    edge tmp;

    h->t[k].dist = d, h->t[k].ind = i;
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
	int n, m, *s, *p, *t, a, b;
	heap h = {NULL, 0};

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	s = (int*)malloc(sizeof(int) * n);
	t = (int*)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n * n; ++i)
		t[i] = -1;
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", p + i);
		s[i] = -1;
		t[i * n + i] = 0;
	}
	fscanf(f, "%d", &m);
	for (int i = 0; i < m; ++i)
	{
		fscanf(f, "%d%d", &a, &b);
		t[(a - 1) * n + b - 1] = p[a - 1], t[(b - 1) * n + a - 1] = p[b - 1];
	}
	h.t = (edge*)malloc(sizeof(edge) * ((n - 1) * (n - 2) / 2 + 1));
    put(&h, 0, 0);
    while (h.num && s[n - 1] < 0)
	{
		edge tmp = get(&h);
        s[tmp.ind] = tmp.dist;
        for (int i = 0; i < n; ++i)
			if (s[i] < 0 && t[tmp.ind * n + i] >= 0)
				put(&h, i, t[tmp.ind * n + i] + tmp.dist);
	}
	fprintf(q, "%d", s[n - 1]);
    return 0;
}
