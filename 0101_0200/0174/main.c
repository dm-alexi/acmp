#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *a, int left, int right)
{
	int i, last, r;
	if (left >= right)
		return;
	r = left + rand() % (right - left + 1);
	i = a[left], a[left] = a[r], a[r] = i;
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (a[i] < a[left])
			 r = a[i], a[i] = a[left], a[left] = r;
	i = a[left], a[left] = a[last], a[last] = i;
	quicksort(a, left, last - 1);
	quicksort(a, last + 1, right);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p;
	double s;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	fscanf(f, "%lf", &s);
	quicksort(p, 0, n - 1);
	for (int i = 0; i < n; ++i)
		if (p[i] > s)
			s = (s + p[i]) / 2;
	fprintf(q, "%f", s);
	return 0;
}
