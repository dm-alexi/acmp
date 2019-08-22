#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a;

    fscanf(f, "%d", &a);
    a /= 10;
    a = a * (a + 1);
    if (a > 0)
        fprintf(q, "%d", a);
    fprintf(q, "25");
    return 0;
}
