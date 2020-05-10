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

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, x, y, t, k, p;

	fscanf(f, "%d%d%d", &n, &x, &y);
	if (x > y)
		x ^= y, y ^= x, x ^= y;
	--n, t = x;
	p = x * y / gcd(x, y);
	k = p / y + p / x;
	t += n / k * p, n %= k;
	p = 0;
	while (n)
		if (n * x - p <= y)
			t += n * x - p, n = 0;
		else
			t += y, n -= 1 + (y + p) / x, p = (y + p) % x;
	fprintf(q, "%d", t);
	return 0;
}
