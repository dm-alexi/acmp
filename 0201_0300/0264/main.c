#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m = 0, k = 0, d;

	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%d", &d);
        if (d <= 0)
			k = 0;
		else if (++k > m)
			m = k;
	}
	fprintf(q, "%d", m);
	return 0;
}
