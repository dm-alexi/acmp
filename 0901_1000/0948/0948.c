#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k;

	fscanf(f, "%d%d", &k, &n);
	fprintf(q, "%d %d", n / k + (n % k > 0), n % k ? n % k : k);
	return 0;
}
