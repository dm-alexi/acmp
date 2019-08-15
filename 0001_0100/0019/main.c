#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, y1, x2, y2, x3, y3, a = 0;
    char c1, c2, c3;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%c%d %c%d %c%d", &c1, &y1, &c2, &y2, &c3, &y3);
    x1 = c1 - 'A', x2 = c2 - 'A', x3 = c3 - 'A', --y1, --y2, --y3;
    for (int i = 0; i < 8; ++i)
        if (i == x1 || i == x2)
            a += 8;
        else for (int j = 0; j < 8; ++j)
            if (j == y1 || j == y2 || abs(x1 - i) == abs(y1 - j) || abs((x3 - i) * (y3 - j)) == 2 || (i == x3 && j == y3))
                ++a;
    fprintf(q, "%d", a - 3);
    return 0;
}
