#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *p, a;

    fscanf(f, "%d", &n);
    p = (int*)malloc(sizeof(int) * n);
	for (int i = 1; i <= n; ++i)
	{
		fscanf(f, "%d", &a);
		p[a - 1] = i;
    }
    for (int i = 0; i < n; ++i)
		fprintf(q, "%d ", p[i]);
	return 0;
}
