#include <stdio.h>

int main()
{
    long a;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    fscanf(f, "%ld", &a);
    fprintf(q,"%ld", a > 0 ? (1 + a) * a / 2 : (1 - a) * a / 2 + 1);
    return 0;
}
