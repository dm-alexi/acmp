#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, s = 0;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d ", p + i);
	for (int i = 0; i < n; ++i)
	{
		int m = i;
		for(int j = i; j < n; ++j)
			if (p[j] > p[m])
				m = j;
		s += (m - i + 1) * p[m];
		i = m;
	}
	fprintf(q, "%d", s);
	return 0;
}
