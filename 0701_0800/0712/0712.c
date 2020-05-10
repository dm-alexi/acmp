#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long w, h, n, k, min, max;

	fscanf(f, "%I64d%I64d%I64d", &w, &h, &n);
	if (w > h)
		w ^= h, h ^= w, w ^= h;
	max = h > n * w ? h : n * w;
	min = sqrt((double)w * h * n);
	k = (max + min) / 2;
	while ((k / w) * (k / h) != n)
	{
		if ((k / w) * (k / h) > n)
			max = k, k = (k + min) / 2;
		else if (((k + 1) / w) * ((k + 1) / h) >= n && ++k)
			break;
		else
			min = k + 1, k = (k + max) / 2;
	}
	while (((k - 1) / w) * ((k - 1) / h) >= n)
		--k;
	fprintf(q, "%I64d", k);
	return 0;
}
