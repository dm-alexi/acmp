#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m;

	fscanf(f, "%d%d", &n, &m);
	for (int i = 0; i < m - n % m; ++i)
		fprintf(q, "%d ", n / m);
	for (int i = 0; i < n % m; ++i)
		fprintf(q, "%d ", n / m + 1);
	return 0;
}
