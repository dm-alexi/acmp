#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long a, b, c;

	fscanf(f, "%I64d%I64d%I64d", &a, &b, &c);
	a = c < a / 2 ? c : a / 2;
	fprintf(q,"%I64d", a < b / 6 ? a : b / 6);
	return 0;
}
