#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m;
	fscanf(f, "%d%d", &n, &m);
	while (n && m)
		if (n > m)
			n %= m;
		else m %= n;
	fprintf(q, "%d", n + m);
	return 0;
}
