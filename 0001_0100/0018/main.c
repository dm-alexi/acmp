#include <stdio.h>
#define N 428

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i;
	int s[N] = {0};

	fscanf(f, "%d", &n);
	s[0] = 1;
	for (int j = 2; j <= n; ++j)
	{
		for (i = 0; i < N; ++i)
			s[i] *= j;
		for (i = 0; i < N; ++i)
			if (s[i] > 999999)
				s[i + 1] += s[i] / 1000000, s[i] %= 1000000;
	}
	for (i = N - 1; s[i] == 0; --i);
	fprintf(q, "%d", s[i]);
	while (--i >= 0)
		fprintf(q, "%06d", s[i]);
	return 0;
}
