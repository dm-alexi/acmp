#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i, k;
	int p[201] = {0};

	fscanf(f, "%d", &n);
	for (i = 0; i < n; ++i)
	{
		fscanf(f, "%d ", &k);
		++p[k + 100];
	}
	for (i = 0; i < 201; ++i)
		while(p[i]--)
			fprintf(q, "%d ", i - 100);
	return 0;
}
