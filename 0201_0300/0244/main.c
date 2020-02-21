#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int i, n, k, p, *s, d[2] = {-1}, m = 0;

	fscanf(f, "%d%d", &n, &k);
	s = (int*)malloc(sizeof(int) * k);
	for (i = 0; i < k; ++i)
		fscanf(f, "%d", s + i);
	for (; i < n; ++i)
	{
		fscanf(f, "%d", &p);
		if (p != s[i % k])
		{
			if (m > 1)
				break;
			d[m++] = i;
		}
		s[i % k] = p;
	}
	if (i < n || (m == 1 && d[0] >= 2 * k && n - d[0] >= k) || (m == 2 && d[1] - d[0] != k))
		fprintf(q, "FAIL");
	else
		fprintf(q, "OK\n%d", (m == 1 && d[0] < 2 * k ? d[0] % k : d[0]) + 1);
	return 0;
}
