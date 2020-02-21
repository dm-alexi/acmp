#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i, a[10] = {0};

	fscanf(f, "%d", &n);
	if (n > 1)
	{
		for (i = 9; i > 1; --i)
			while (n % i == 0)
				n /= i, ++a[i];
		if (n > 1)
			fprintf(q, "-1");
		else for(i = 2; i < 10; ++i)
			while (a[i]--)
				fprintf(q, "%d", i);
	}
	else fprintf(q, n ? "1" : "10");
	return 0;
}
