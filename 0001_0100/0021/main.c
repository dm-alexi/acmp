#include <stdio.h>

int main()
{
    int a, b, c;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d %d %d", &a, &b, &c);
    if (a > b)
        a ^= b ^= a ^= b;
    if (a > c)
        a ^= c ^= a ^= c;
    if (b > c)
        b ^= c ^= b ^= c;
    fprintf(q, "%d", c - a);
    return 0;
}
