#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a[10] = {0}, k, n;
    long long l = 0;

    fscanf(f, "%d%d", &n, &k);
    for (int i = 9; i > 1; --i)
		while (k % i == 0)
			k /= i, ++a[i];
	if (k > 1)
		fprintf(q, "NO");
	else
	{
		for (int i = 2; i < 10; ++i)
			for (int j = 0; j < a[i]; ++j)
				l = 10 * l + i;
		fprintf(q, l <= n ? "YES" : "NO");
	}
    return 0;
}
