#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0, m[101] = {0}, a;

	fscanf(f, "%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		fscanf(f, "%d", &a);
		if (m[a] && i - m[a] > k)
			k = i - m[a];
		m[a] = i;
	}
	fprintf(q, "%d", k);
	return 0;
}
