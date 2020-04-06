#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, d;
	long long v;

	fscanf(f, "%d%I64d%d", &n, &v, &k);
	d = v / k + 1 + (v % k > 0);
	v = d > n ? (2 * v - (n - 1) * k) * n / 2 : (v + v % k) * (d - (v % k > 0)) / 2;
	fprintf(q, "%s %I64d", d > n ? "YES" : "NO", v);
	return 0;
}
