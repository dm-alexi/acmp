#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, a = 0, i;

	fscanf(f, "%d", &n);
	for (i = 0; i < 3; ++i)
		a += n % 10, n /= 10;
	for(; i < 6; ++i)
		a -= n % 10, n /= 10;
	fprintf(q, a ? "NO" : "YES");
	return 0;
}
