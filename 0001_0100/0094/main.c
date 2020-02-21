#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k;

	fscanf(f, "%d%d%d", &n, &m, &k);
	if (n <= k && n < m)
		fprintf(q, "NO");
	else fprintf(q, "%d", n >= m ? 1 : (m - n - 1) / (n - k) + 2);
	return 0;
}
