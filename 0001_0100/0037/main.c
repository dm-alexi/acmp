#include <stdio.h>
#include <math.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, a, b, c, d;
    long long j;
    double k;

    fscanf(f, "%d%lf", &n, &k);
    j = round(k * 1000);
    while(n--)
    {
        fscanf(f,"%d%d%d%d", &a, &b, &c, &d);
        if(1000000LL * (c * c + d * d) > j * j * (a * a + b * b))
            break;
    }
    fprintf(q, n == -1 ? "Yes" : "No");
    return 0;
}
