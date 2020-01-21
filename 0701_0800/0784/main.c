#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n;
    unsigned long long a, b;

    fscanf(f, "%d%I64u%I64u", &n, &a, &b);
    while (a != b)
		if (a > b)
			a >>= 1;
		else
			b >>= 1;
    fprintf(q, "%I64u", a);
    return 0;
}
