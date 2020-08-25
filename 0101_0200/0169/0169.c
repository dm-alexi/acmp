#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, *p, r;

	fscanf(f, "%d%d", &n, &k);
	if (!(r = (n == k)) && n % 2 == k % 2)
	{
		p = (int*)calloc(k, sizeof(int));
		p[0] = 1;
		for (int i = 2, t; i <= k; ++i)
		{
			t = p[1];
			for (int j = i % 2 + 1; j < k - 1; j += 2)
				p[j] = p[j - 1] + p[j + 1];
			p[0] = t;
		}
		r = p[n - 1];
	}
	fprintf(q, "%d", r);
	return 0;
}
