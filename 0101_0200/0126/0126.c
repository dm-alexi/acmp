#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int *m, n, s;

	fscanf(f, "%d", &n);
	m = (int*)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n * n; ++i)
		fscanf(f, "%d", m + i);
	s = m[1] + m[2] + m[n + 2];
	for (int i = 0; i < n - 2; ++i)
		for (int j = i + 1; j < n - 1; ++j)
			for (int k = j + 1; k < n; ++k)
				if (m[i * n + j] + m[j * n + k] + m[k * n + i] < s)
					s = m[i * n + j] + m[j * n + k] + m[k * n + i];
	fprintf(q, "%d", s);
	return 0;
}
