#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i = 1, a = 1, b;

	fscanf(f, "%d", &n);
	b = n;
	if (n % 4)
	{
		fprintf(q, "%d 1 %d %d\n", i, 0, a++);
		if (n > 1)
			fprintf(q, "%d 2 %d %d\n", i++, a++, n % 4 > 2 ? b-- : 0);
		if (n > 3)
		{
			fprintf(q, "%d 1 %d %d\n", i, n % 4 > 1 ? b-- : 0, a++);
			fprintf(q, "%d 2 %d %d\n", i++, a++, b--);
		}
	}
	while (a < b)
	{
		fprintf(q, "%d 1 %d %d\n", i, b--, a++);
		fprintf(q, "%d 2 %d %d\n", i++, a++, b--);
	}
	return 0;
}
