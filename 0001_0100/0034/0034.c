#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, m = 1, r = 0, i, a = 0;
	char *p;

	fscanf(f, "%d%d\n", &n, &k);
	if (n > k)
	{
		for (i = 0; i < k; ++i, m *= 10)
			a = a * 10 + fgetc(f) - '0';
		p = (char*)calloc(m, 1);
		p[a] = 1;
		for (; i < n; ++i)
			if (p[a = a % (m / 10) * 10 + fgetc(f) - '0'] && (r = 1))
				break;
			else p[a] = 1;
	}
	fprintf(q, r ? "YES" : "NO");
	return 0;
}
