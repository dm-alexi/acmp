#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, a = 0;

	fscanf(f, "%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int k;
			fscanf(f, "%d", &k);
			if (k && j < i)
				++a;
		}
	fprintf(q, "%d", a);
	return 0;
}
