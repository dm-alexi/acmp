#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
	int *t;
	int num;
} heap;

void heapify(heap *h, int i)
{
	int left = 2 * i + 1, right = 2 * i + 2, big = i;

	if (left < h->num && h->t[left] > h->t[big])
		big = left;
	if (right < h->num && h->t[right] > h->t[big])
		big = right;
    if (big != i)
	{
		int tmp = h->t[big];
		h->t[big] = h->t[i];
		h->t[i] = tmp;
		heapify(h, big);
	}
}

void put(heap *h, int n)
{
    int	k = h->num++;

	h->t[k] = n;
    while (k && h->t[k] > h->t[(k - 1) / 2])
		n = h->t[k], h->t[k] = h->t[(k - 1) / 2], h->t[(k - 1) / 2] = n, k = (k - 1) / 2;
}

int get(heap *h)
{
	int tmp = h->t[0];

	h->t[0] = h->t[--h->num];
	heapify(h, 0);
	return tmp;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0, a, b;
	heap h = {NULL, 0};

	fscanf(f, "%d", &n);
	h.t = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", &a);
		put(&h, a);
	}
	while (h.num > 1 && ++k)
	{
		a = get(&h) - 1;
		b = get(&h) - 1;
		if (a)
			put(&h, a);
		if (b)
			put(&h, b);
	}
	fprintf(q, "%d", k);
	return 0;
}
