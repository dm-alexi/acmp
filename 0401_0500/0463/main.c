#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int m, k, i, n = 0, d = 1;
	char s[10001];

	fscanf(f, "%d%d%s", &k, &m, s);
	i = strlen(s);
	while (--i >= 0)
	{
		s[i] = s[i] > '9' ? s[i] - 'A' + 10 : s[i] - '0';
		n += s[i] * d;
		d = d * k % m;
		n %= m;
	}
	fprintf(q, "%d", n);
	return 0;
}
