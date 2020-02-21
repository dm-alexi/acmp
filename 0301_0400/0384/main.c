#include <stdio.h>

int gcd(int m, int n)
{
	while (n && m)
		if (n > m)
			n %= m;
		else
			m %= n;
	return n + m;
}

int fiblast(int a)
{
	int r1 = 1, r2 = 1, rt;

	if (a == 0)
		return 0;
	if (a < 3)
		return 1;
	for (int i = 2; i < a; ++i)
		rt = r1, r1 = (r1 + r2) % 1000000000, r2 = rt;
	return r1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b;

	fscanf(f, "%d%d", &a, &b);
	fprintf(q, "%d", fiblast(gcd(a, b)));
	return 0;
}
