#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, n, m;

	fscanf(f, "%d%d", &a, &b);
	n = a, m = b;
	while (n && m)
		if (n > m)
			n %= m;
		else m %= n;
	fprintf(q, "%d", a / (n + m) * b);
	return 0;
}
