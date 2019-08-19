#include <stdio.h>

int main()
{
    int a, b, c;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d%d%d", &a, &b, &c);
    fprintf(q, "%s", a * b == c ? "YES" : "NO");
    return 0;
}

