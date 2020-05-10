#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	double m, p, x = 30.0, y = 4000.0;
	char s[8];

	fscanf(f, "%d%lf", &n, &m);
	while (n--)
	{
		fscanf(f, "%lf%s", &p, s);
		if (((s[0] == 'c' && p < m) || (s[0] == 'f' && p > m)) && y > p + (m - p) / 2)
			y = p + (m - p) / 2;
		else if (((s[0] == 'c' && p > m) || (s[0] == 'f' && p < m)) && x < m + (p - m) / 2)
			x = m + (p - m) / 2;
		m = p;
	}
	fprintf(q, "%f %f", x, y);
	return 0;
}
