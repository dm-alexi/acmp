#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, tmp, k = 0, e = 0, v;
    char *s = "YES", *m, *lst, *st;

    fscanf(f, "%d", &n);
    m = (char*)malloc(n * n);
    for (int i = 0; i < n * n; ++i)
	{
		fscanf(f, "%d", &tmp);
		m[i] = tmp;
	}
	st = (char*)malloc(n);
	lst = (char*)calloc(1, n);
	st[k++] = 0;
	while (k)
	{
		v = st[--k];
		lst[v] = 1;
		for (int i = 0; i < n; ++i)
			if (m[v * n + i])
				if (lst[i])
				{
					s = "NO";
					break;
				}
				else
					st[k++] = i, m[i * n + v] = 0, ++e;
	}
	fprintf(q, e != n - 1 ? "NO" : s);
    return 0;
}
