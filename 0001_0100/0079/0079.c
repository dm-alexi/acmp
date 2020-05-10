#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b;
	char *s = "0000111162481397646455556666179368421919";

	fscanf(f, "%d%d", &a, &b);
	fprintf(q, "%c", s[a % 10 * 4 + b % 4]);
	return 0;
}
