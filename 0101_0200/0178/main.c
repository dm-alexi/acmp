#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *m, *t, k = 0;

    t = (int*)malloc(sizeof(int) * 2000001);
    for (int i = 0; i < 2000001; ++i)
		t[i] = 0;
    fscanf(f, "%d", &n);
    m = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", m + i);
		if (++t[m[i] + 1000000] > t[k] || (t[m[i] + 1000000] == t[k] && k > m[i] + 1000000))
			k = m[i] + 1000000;
	}
	for (int i = 0; i < n; ++i)
		if (m[i] != k - 1000000)
			fprintf(q, "%d ", m[i]);
	for (int i = 0; i < t[k]; ++i)
		fprintf(q, "%d ", k - 1000000);
    return 0;
}
