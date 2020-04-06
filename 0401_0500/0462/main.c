#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	fprintf(q, "%d", n - (n / 2 + n / 3 - n / 6 + n / 5 - n / 15 - n / 10 + n / 30));
	return 0;
}
