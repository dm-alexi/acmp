#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[7];

	fscanf(f, "%s%d", s, &n);
	fprintf(q, n % 2 || *s == 'H' ? "Yes" : "No" );
	return 0;
}
