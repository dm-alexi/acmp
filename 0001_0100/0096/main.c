#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, m, x, y, k = 0;

    fscanf(f, "%d%d%d%d", &n, &m, &y, &x);
    while (y != 1 && x != 1 && x != m && y != n)
        k += 2 * (m + n - 2), --x, --y, n -= 2, m -= 2;
    k += y == 1 ? x : x == m ? m + y - 1 : y == n ? 2 * m + n - 1 : 2 * (m + n - 1) - y;
    fprintf(q, "%d", k);
    return 0;
}
