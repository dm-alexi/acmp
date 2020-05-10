#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, s = 0;

	fscanf(f, "%d%d", &n, &k);
	if (k == 1)
		s = n;
	else while (k % 2)
		s += n /= 2, k = k / 2 + 1;
	fprintf(q, "%d", s + k / 2);
	return 0;
}
