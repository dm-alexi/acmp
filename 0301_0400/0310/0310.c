#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k, x, y, a;

	fscanf(f, "%d", &k);
	while (k-- && fscanf(f, "%d%d%d", &x, &y, &a))
		putc(a < 3 || x % a + y % a == 2 ? '1' : '0', q);
	return 0;
}
