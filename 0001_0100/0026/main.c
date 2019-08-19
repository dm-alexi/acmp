#include <stdio.h>

int main()
{
    int x1, y1, r1, x2, y2, r2, m;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
    m = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    fprintf(q, m > (r1 + r2) * (r1 + r2) || m < (r2 - r1) * (r2 - r1) ? "NO" : "YES");
    return 0;
}
