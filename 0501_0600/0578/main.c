#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k;
	char s[21], *t = s + 20;

	*t = '\0';
	fscanf(f, "%d", &n);
	while (n)
	{
		k = n % 3 ? n % 3 : 3;
		*--t = '0' + k;
		n = (n - k) / 3;
	}
	fprintf(q, t);
	return 0;
}
