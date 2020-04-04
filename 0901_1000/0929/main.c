#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long n;;

	fscanf(f, "%I64d", &n);
	fprintf(q, "%I64d %I64d", n % 6 ? n / 6 + 7 - n % 6 : n / 6, n * 6);
	return 0;
}
