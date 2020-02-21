#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *m;
	char *s = "NO";

	fscanf(f, "%d", &n);
	m = (int*)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n * n; ++i)
	{
		fscanf(f, "%d", m + i);
		if (m[i] == 100000)
			m[i] = INT_MAX;
	}
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (m[i * n + k] < INT_MAX && m[k * n + j] < INT_MAX && m[i * n + k] + m[k * n + j] < m[i * n + j])
					m[i * n + j] = m[i * n + k] + m[k * n + j];
	for (int i = 0; i < n; ++i)
		if (m[i * n + i] < 0 && (s = "YES"))
			break;
	fprintf(q, s);
	return 0;
}
