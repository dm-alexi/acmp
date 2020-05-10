#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a;

	fscanf(f, "%d", &a);
	fprintf(q, "%d", a > 0 ? (1 + a) * a / 2 : (1 - a) * a / 2 + 1);
	return 0;
}
