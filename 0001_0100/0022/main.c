#include <stdio.h>

int main()
{
    unsigned x, n;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d", &x);
    for(n = 0; x != 0; x &= x - 1, ++n);
    fprintf(q, "%d", n);
    return 0;
}
