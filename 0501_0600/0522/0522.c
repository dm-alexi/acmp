#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, p[64001] = {0}, s[64001] = {0};

	fscanf(f, "%d%d", &n, &m);
	for (int i = 0, a; i < n; ++i)
		fscanf(f, "%d", &a), p[a + 32000] = 1;
	for (int i = 0, a; i < m; ++i)
		fscanf(f, "%d", &a), s[a + 32000] = 1;
	for (n = 0; n < 64001; ++n)
		if (p[n] ^ s[n])
			break;
	putc(n == 64001 ? '1' : '0', q);
	return 0;
}
