#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int r1, r2, r3;

	fscanf(f, "%d%d%d", &r1, &r2, &r3);
	fprintf(q, r1 >= r2 + r3 ? "YES" : "NO");
	return 0;
}
