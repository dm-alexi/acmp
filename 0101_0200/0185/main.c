#include <stdio.h>
#include <stdlib.h>

int check(char *m, int n, int k, char *s)
{
	int r = 0;

	for (int i = 0; i < n; ++i)
		if (m[k * n + i] && !s[i] && (s[i] = 1))
			r += 1 + check(m, n, i, s);
	return r;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, x, y;
	char *s, *m;

	fscanf(f, "%d%d", &n, &k);
	m = (char*)calloc(n * n, 1);
	s = (char*)calloc(n, 1);
	while (fscanf(f, "%d%d", &x, &y) > 1)
		m[(x - 1) * n + y - 1] = 1;
	fprintf(q, check(m, n, k - 1, s) == n - 1 ? "Yes" : "No");
	return 0;

}
