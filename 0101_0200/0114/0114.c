#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, r, m;

	fscanf(f, "%d%d", &n, &k);
	r = (k - 1) * (k - 1);
	m = k - 1;
	for (int i = 2, t; i < n; ++i)
		t = m, m = r, r = (r + t) * (k - 1);
	fprintf(q, "%d", r + m);
	return 0;
}
