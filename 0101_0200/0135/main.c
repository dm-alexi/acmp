#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *m;

	fscanf(f, "%d", &n);
    m = (int*)malloc(sizeof(int) * n * n);
    for (int i = 0; i < n * n; ++i)
		fscanf(f, "%d", m + i);
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (m[i *n + k] + m[k * n + j] < m[i * n + j])
					m[i * n + j] = m[i *n + k] + m[k * n + j];
	for (int i = 0; i < n * n; ++i)
		fprintf(q, "%d%c", m[i], (i + 1) % n ? ' ' : '\n');
    return 0;
}
