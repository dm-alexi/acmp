#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, i;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; ++i)
		fscanf(f, "%d ", p + i);
	for (i = 1; i < n; ++i)
	{
		if((n - 1) % i || p[i] != p[0])
			continue;
		int j;
		for (j = i; j < n; ++j)
			if (p[j] != p[j % i])
				break;
		if (j == n)
			break;
	}
	fprintf(q, "%d", i);
	return 0;
}
