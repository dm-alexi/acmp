#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0;
	char s[34];

	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%s", s);
		if (s[0] == s[3])
			++k;
	}
	fprintf(q, "%d", k);
	return 0;
}
