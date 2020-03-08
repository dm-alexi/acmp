#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, a, b, p = 0;
	char s[8][8];

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			s[i][j] = 0;
	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%d%d", &a, &b);
		s[a - 1][b - 1] = 1;
	}
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			if (s[i][j])
			{
				if (i == 0 || !s[i - 1][j])
					++p;
				if (i == 7 || !s[i + 1][j])
					++p;
				if (j == 0 || !s[i][j - 1])
					++p;
				if (j == 7 || !s[i][j + 1])
					++p;
			}
	fprintf(q, "%d", p);
	return 0;
}
