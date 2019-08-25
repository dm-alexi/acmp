#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a, b, r = 0;

    for (int i = 0; i < 4; ++i)
        fscanf(f, "%d %d", &a, &b), r += a - b;
    fprintf(q, !r ? "DRAW" : r > 0 ? "1" : "2");
    return 0;
}
