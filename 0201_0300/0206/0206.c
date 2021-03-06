#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
	int ind, t1, t2;
	struct edge *next;
} edge;

typedef struct heap
{
	edge *t;
	int num;
} heap;

void heapify(heap *h, int i)
{
	int left = 2 * i + 1, right = 2 * i + 2, small = i;

	if (left < h->num && h->t[left].t2 < h->t[small].t2)
		small = left;
	if (right < h->num && h->t[right].t2 < h->t[small].t2)
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
	int k = h->num++;
	edge tmp;

	h->t[k].t2 = d, h->t[k].ind = i;
	while (k && h->t[k].t2 < h->t[(k - 1) / 2].t2)
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
	int n, *s, e, m;
	heap h = {NULL, 0};
	edge **t;

	fscanf(f, "%d%d%d", &n, &e, &m);
	--e;
	t = (edge**)malloc(sizeof(edge*) * n);
	s = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		s[i] = -1, t[i] = NULL;
	h.t = (edge*)malloc(sizeof(edge) * m * n);
	for (int i = 0, k, a, b, t1, t2; i < m; ++i)
	{
		fscanf(f, "%d%d%d", &k, &a, &t1);
		for (int j = 1; j < k; ++j)
		{
			fscanf(f, "%d%d", &b, &t2);
			edge *tmp = t[a - 1];
			t[a - 1] = (edge*)malloc(sizeof(edge));
			t[a - 1]->ind = b - 1;
			t[a - 1]->t1 = t1;
			t[a - 1]->t2 = t2;
			t[a - 1]->next = tmp;
			a = b;
			t1 = t2;
		}
	}
	put(&h, 0, 0);
	while (h.num && s[e] < 0)
	{
		edge tmp = get(&h);
		s[tmp.ind] = tmp.t2;
		for (edge *v = t[tmp.ind]; v; v = v->next)
			if (s[v->ind] < 0 && tmp.t2 <= v->t1)
				put(&h, v->ind, v->t2);
	}
	fprintf(q, "%d", s[e]);
	return 0;
}
