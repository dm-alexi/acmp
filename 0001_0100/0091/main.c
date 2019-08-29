#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a[10001], b[10001], i, j, n;

    fscanf(f, "%d", &n);
    a[1] = 2, a[2] = 3, a[3] = 4, a[4] = 7, b[1] = 1, b[2] = 5, b[3] = 6, b[4] = 8;
    for(i = 5, j = 4; i <= n; ++i)
    {
        a[i] = b[i - 1] + b[i - 3];
        for (int k = a[i - 1] + 1; j <= n && k < a[i]; ++k, ++j)
                b[j] = k;
    }
    fprintf(q, "%d\n%d", a[n], b[n]);
    return 0;
}
