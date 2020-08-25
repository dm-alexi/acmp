#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, p[3] = {0};
	const int l[] = {0, 0, 0, 5, 5, 9, 10, 10, 14, 15, 18, 19, 20, 23, 24, 27, 28, 29, 32, 33};

	fscanf(f, "%d%d", &k, &n);
	p[0] = k;
	while (--n)
	{
		p[2] = p[1], p[1] = p[0], p[0] = k < 20 ? l[k] : k % 20 < 10 ? (k / 10 - 1) * 18 + l[k % 20 + 10] : k / 20 * 36 + l[k % 20];
		k = p[0] + p[1] + p[2];
	}
	fprintf(q, "%d", k);
	return 0;
}
