#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[7];

	fscanf(f, "%s", s);
	fprintf(q, s[0] + s[1] + s[2] - s[3] - s[4] - s[5] ? "NO" : "YES");
	return 0;
}
