#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, kf = 1, nf = 1;

	fscanf(f, "%d%d", &n, &k);
	for (int i = 1; i <= k; ++i)
		kf *= i, nf *= n - i + 1;
	fprintf(q, "%d", nf * nf / kf);
	return 0;
}
