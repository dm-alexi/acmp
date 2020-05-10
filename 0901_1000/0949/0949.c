#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k, a;

	fscanf(f, "%d%d%d", &n, &m, &k);
	while (--n)
		a = m, m = k - m, k = a;
	fprintf(q, "%d %d", m, k);
	return 0;
}
