#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k1, l1, m1, k2, l2, m2, a;

	fscanf(f, "%d%d%d%d%d%d", &k1, &l1, &m1, &k2, &l2, &m2);
	a = (k1 * (100 - l1) < k2 * (100 - l2) ? k1 * (100 - l1) : k2 * (100 - l2)) / 100;
	fprintf(q, "%d", (k1 - a) * m1 + (k2 - a) * m2);
	return 0;
}
