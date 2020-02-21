#include <stdio.h>
#include <stdlib.h>

int vcount(int *a, int n, int p)
{
	int v = 1;

	for (int i = 0, s = 0; i < n; ++i)
	{
		s += a[i];
		if (s > p)
			++v, s = a[i];
	}
	return v;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, *a, pmax = 0, l, r = 0, p;

	fscanf(f, "%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", a + i);
		if (a[i] > pmax)
			pmax = a[i];
		r += a[i];
	}
	fscanf(f, "%d", &k);
	l = pmax, p = (l + r) / 2;
	while (l < r)
	{
		int c = vcount(a, n, p);

		if (c == k || (c > k && vcount(a, n, p + 1) <= k && ++p))
			break;
		else if (c < k)
			l = p + 1, p = (p + r) / 2;
		else
			r = p, p = (p + l) / 2;
	}
	while (p > pmax && vcount(a, n, p - 1) <= k)
		--p;
	fprintf(q, "%d", p);
	return 0;
}
