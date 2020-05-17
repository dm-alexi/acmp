#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i = 1;

	fscanf(f, "%d", &n);
	if (n % 4)
	{
		fprintf(q, "1 1 0 1\n");
		if (n > 1)
			fprintf(q, "%d 2 2 %d\n", i++, n % 4 == 3 ? n-- : 0);
		if (n > 2 && n % 4 == 1)
			fprintf(q, "2 1 0 3\n%d 2 4 %d\n", i++, n--);
	}
	for (; 2 * i < n; ++i, n -= 2)
		fprintf(q, "%d 1 %d %d\n%d 2 %d %d\n", i, n, 2 * i - 1, i, 2 * i, n - 1);
	return 0;
}
