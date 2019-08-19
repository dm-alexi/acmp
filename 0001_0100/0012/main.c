#include <stdio.h>

int between(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (x1 == x2)
        return (x <= x1 && x >= x3) || (x >= x1 && x <= x3);
    if (y1 == y2)
        return (y <= y1 && y >= y3) || (y >= y1 && y <= y3);
    double k = ((double)(y2 - y1)) / (x2 - x1);
    return (k * (x - x1) - (y - y1)) * (k * (x - x3) - (y - y3)) <= 0;
}

int main()
{
    int n, k = 0, x, y, x1, y1, x2, y2, x3, y3, x4, y4;

    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    fscanf(f, "%d", &n);
    while(n--)
    {
        fscanf(f, "%d%d%d%d%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        if (between(x, y, x1, y1, x2, y2, x3, y3) && between(x, y, x1, y1, x4, y4, x2, y2))
            ++k;
    }
    fprintf(q, "%d", k);
    return 0;
}
