#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *p, s = 0, c, i = 2, j = 0;

    fscanf(f, "%d", &n);
    p = (int*)malloc(sizeof(int) * n);
    if (n > 0)
    {
    	for (int k = 0; k < n; ++k)
			fscanf(f, "%d", p + k);
		s = p[0];
		if (n > 1)
		{
			qsort(p, n, sizeof(int), cmp);
			c = s = p[0] + p[1];
			while (i < n)
				if (p[i] <= p[j] + p[j + 1])
					c += p[i++];
				else
				{
					if (c > s)
						s = c;
					c -= p[j++];
				}
			if (c > s)
				s = c;
		}
    }
    fprintf(q, "%d", s);
	return 0;
}
