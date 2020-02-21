#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, b, g, r;

	fscanf(f, "%d%d", &n, &m);
	b = n / 5 * m + m / 5 * n - (n / 5) * (m / 5);
	g = (n / 3 - n / 15) * (m - m / 5) + (n - n / 3 - n / 5 + n / 15) * (m / 3 - m / 15);
	r = (n / 2 - n / 10 - n / 6 + n / 30) * (m - m / 5 - m / 3 + m / 15) +
		(n - n / 2 - n / 3 - n / 5 + n / 10 + n / 6 + n / 15 - n / 30) * (m / 2 - m / 10 - m / 6 + m / 30);
	fprintf(q, "RED : %d\nGREEN : %d\nBLUE : %d\nBLACK : %d", r, g, b, n * m - r - g - b);
	return 0;
}
