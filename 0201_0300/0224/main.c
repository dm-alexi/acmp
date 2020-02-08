#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, a, b, c, min1, min2, max1, max2, max3;
    long long x, y;

    fscanf(f, "%d%d%d%d", &n, &a, &b, &c);
    min1 = a < b ? a : b;
    min2 = a > b ? a : b;
    max1 = min2;
    max2 = min1;
    if (c > max1)
        max3 = max2, max2 = max1, max1 = c;
    else if (c > max2)
        max3 = max2, max2 = c;
    else
		max3 = c;
    if (c < min1)
		min2 = min1, min1 = c;
    else if (c < min2)
        min2 = c;
	while (n-- > 3)
	{
		fscanf(f, "%d", &a);
		if (a > max1)
            max3 = max2, max2 = max1, max1 = a;
        else if (a > max2)
            max3 = max2, max2 = a;
        else if (a > max3)
            max3 = a;
        if (a < min1)
            min2 = min1, min1 = a;
        else if (a < min2)
            min2 = a;
	}
	x = (long long)max1 * max2 * max3;
	y = (long long)max1 * min1 * min2;
    fprintf(q, "%I64d", x > y ? x : y);
    return 0;
}
