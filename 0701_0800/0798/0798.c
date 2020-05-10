#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long n, m, i, j, c;

	fscanf(f, "%I64d%I64d%I64d%I64d%I64d", &n, &m, &i, &j, &c);
	fprintf(q, !(m % 2 && n % 2) ? "equal" : (((i - 1) * n + j) % 2 == c) ? "white" : "black");
	return 0;
}
