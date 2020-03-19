#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[5];

	fscanf(f, "%s", s);
	fprintf(q, s[0] == s[3] && s[1] == s[2] ? "YES" : "NO");
	return 0;
}
