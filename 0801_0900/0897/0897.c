#include <stdio.h>
#include <math.h>

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
	int n;
	const int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	fscanf(f, "%d", &n);
	while (n--)
	{
		int p[10] = {0}, t, j = 0, l, res;

		fscanf(f, "%d", &t);
		l = sqrt(t) + 1;
		for (int i = 0; i < 25 && t > 1; ++i)
			if (t % prime[i] == 0)
			{
				while (t % prime[i] == 0)
					t /= prime[i], ++p[j];
				++j;
			}
		for (int i = 101; i < l && t > 1; i += 2)
			if (t % i == 0)
			{
				while (t % i == 0)
					t /= i, ++p[j];
				++j;
			}
		res = (t == 1 && j == 1 && p[0] > 1);
		if (t == 1 && j > 1)
		{
			l = gcd(p[0], p[1]);
			for (int i = 2; i < j; ++i)
				l = gcd(l, p[i]);
			if (l > 1)
				res = 1;
		}
		fprintf(q, res ? "YES\n" : "NO\n");
	}
	return 0;
}
