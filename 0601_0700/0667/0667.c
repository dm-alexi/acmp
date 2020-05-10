#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k;

	fscanf(f, "%d%d%d", &n, &m, &k);
	fprintf(q, "%d", k > 2 && m >= 2 * (n / (k - 2) + (n % (k - 2) > 0)) ? (m + n) / k + ((m + n) % k > 0) : 0);
	return 0;
}
