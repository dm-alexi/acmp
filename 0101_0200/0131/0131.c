#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, t, s, k = -1, a = -1;
	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		fscanf(f, "%d%d", &t, &s);
		if (s && t > k)
			k = t, a = i;
	}
	fprintf(q, "%d", a);
	return 0;
}
