#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *rev(char *s)
{
	int n = strlen(s);
	memmove(s + 24 - n, s, n + 1);
	for (int i = 0; i < 24 - n; ++i)
		s[i] = '0';
	return s;
}

char *sum(char *a, char *b, char *s)
{
	int j = 23;
	char str[25];

	for (int i = 23; i > 6; --i)
	{
		int d = a[i] + b[i] - 2 * '0';
		str[j--] = d % 10 + '0';
		if (d > 9)
			str[j--] = '1';
	}
	while (j >= 0)
		str[j--] = '0';
	str[24] = '\0';
	strcpy(s, str);
	return s;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char a[25], b[25], c[25], abc[25], acb[25], bca[25];
	long long x, y, z, t;

	fscanf(f, "%s%s%s", a, b, c);
	x = atoll(sum(rev(c), sum(rev(a), rev(b), abc), abc));
	y = atoll(sum(b, sum(a, c, acb), acb));
	z = atoll(sum(a, sum(b, c, bca), bca));
	if (x == y && y == z)
		fprintf(q, "NO\n%I64d", x);
	else
	{
		if (x > y)
			t = x, x = y, y = t;
		if (x > z)
			t = z, z = x, x = t;
		if (y > z)
			t = z, z = y, y = t;
		fprintf(q, "YES\n%I64d\n%I64d", x, y > x ? y : z);
		if (z > y && y > x)
			fprintf(q, "\n%I64d", z);
	}
	return 0;
}
