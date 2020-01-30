#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *m, p = 0;

	fscanf(f, "%d", &n);
    m = (int*)malloc(sizeof(int) * n * n);
    for (int i = 0; i < n * n; ++i)
		fscanf(f, "%d", m + i);
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (m[i *n + k] >= 0 && m[k * n + j] >= 0 &&
					(m[i * n + j] < 0 || (m[i *n + k] + m[k * n + j] < m[i * n + j])))
					m[i * n + j] = m[i *n + k] + m[k * n + j];
	for (int i = 1; i < n * n - 1; ++i)
		if (m[i] > p)
			p = m[i];
	fprintf(q, "%d", p);
    return 0;
}
