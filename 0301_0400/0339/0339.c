#include <stdio.h>

int leap(int n)
{
	return ((n % 4 == 0 && n % 100) || (n % 400 == 0));
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int d1, d2, m1, m2, y1, y2;
	const int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	fscanf(f, "%d.%d.%d%d.%d.%d", &d1, &m1, &y1, &d2, &m2, &y2);
	d1 += (leap(y1) && m1 > 2);
	d2 += (leap(y2) && m2 > 2);
	--m1, -- m2;
	while (--m1 >= 0)
		d1 += m[m1];
	while (--m2 >= 0)
		d2 += m[m2];
	while (--y2 >= y1)
		d2 += 365 + leap(y2);
	fprintf(q, "%d", d2 - d1 + 1);
	return 0;
}
