#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c;

	fscanf(f, "%d%d%d", &a, &b, &c);
	if (!a && !b && !c)
		putc('0', q);
	else
	{
		if (a)
			fprintf(q, b > 0 ? "%d+" : "%d", a);
		if (b)
			fprintf(q, b > 1 || b < -1 ? "%dx" : b < 0 ? "-x" : "x", b);
		if (c > 0 && (a != 0 || b != 0))
			putc('+', q);
		if (c)
			fprintf(q, c > 1 || c < -1 ? "%dy" : c < 0 ? "-y" : "y", c);
	}
	return 0;
}
