#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, a, b;

	fscanf(f, "%d%d%d", &n, &a, &b);
	fprintf(q, "%d", 2 * n * a * b);
    return 0;
}
