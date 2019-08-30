#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, *p, s[] = {0, 0};

    fscanf(f, "%d", &n);
    p = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        fscanf(f, "%d", p + i);
    for (int i = 0, j = n - 1, k = 0; k < n; ++k)
        s[k % 2] += p[i] < p[j] ? p[j--] : p[i++];
    fprintf(q, "%d:%d", s[0], s[1]);
    return 0;
}
