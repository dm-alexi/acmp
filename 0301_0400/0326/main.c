#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *m, k = 0, t[201] = {0};

    fscanf(f, "%d", &n);
    m = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", m + i);
		if (++t[m[i] + 100] > t[k] || (t[m[i] + 100] == t[k] && k > m[i] + 100))
			k = m[i] + 100;
	}
	for (int i = 0; i < n; ++i)
		if (m[i] != k - 100)
			fprintf(q, "%d ", m[i]);
	for (int i = 0; i < t[k]; ++i)
		fprintf(q, "%d ", k - 100);
    return 0;

}
