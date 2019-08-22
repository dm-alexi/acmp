#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, m;

    fscanf(f,"%d%d", &n, &m);
    fprintf(q, "%d", !m ? 1 : m == 1 ? n : n / (m - 1) * (2 * n - m + 1 + n / (m - 1) * (1 - m)) / 2);
    return 0;
}
