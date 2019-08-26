#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, a;

    fscanf(f, "%d%d", &n, &a);
    fprintf(q, a * (1 - cos(PI / n)) / (2 * sin(PI / n)) < 1 ? "YES" : "NO" );
    return 0;
}
