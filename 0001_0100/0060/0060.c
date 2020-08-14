#include <stdio.h>
#include <math.h>

int issim(int a)
{
	if (a == 2)
		return 1;
	if (a == 1 || a % 2 == 0)
		return 0;
	for (int i = 3; i <= sqrt(a); i += 2)
		if (a % i == 0)
			return 0;
	return 1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m = 0, i, k = 1;

	fscanf(f, "%d", &n);
	for (i = 3; ; i += 2)
		if (issim(i) && issim(++k) && ++m == n)
			break;
	fprintf(q, "%d", i);
	return 0;
}
