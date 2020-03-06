#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct product
{
	int res;
	int quan;
	int good;
} product;

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, s = 0, ps = 0;
	product *d;

	fscanf(f,"%d\n", &n);
	d = (product*)malloc(sizeof(product) * n);
	for (int i = 0; i < n; ++i)
	{
		char c;
		fscanf(f, "%c %d\n", &c, &d[i].quan);
		d[i].good = (c == '+');
		s += d[i].quan;
	}
	for (int i = 0; i < n; ++i)
		ps += (d[i].res = d[i].good ? ceil(100.0 * d[i].quan / s) : floor(100.0 * d[i].quan / s));
	for (int i = 0; i < n && ps != 100; ++i)
	{
		if (ps < 100 && !d[i].good && 100 * d[i].quan % s)
			++d[i].res, ++ps;
		else if (ps > 100 && d[i].good && 100 * d[i].quan % s)
			--d[i].res, --ps;
	}
	for (int i = 0; i < n; ++i)
		fprintf(q, "%d\n", d[i].res);
	return 0;
}
