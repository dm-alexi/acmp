#include <stdio.h>
#include <stdlib.h>

#define N 428

int *mult(int *s, int m)
{
    int i, sn, *r = (int*)calloc(N, sizeof(int));
    for (sn = N - 1; s[sn] == 0; --sn);
    for (i = 0; i <= sn; ++i)
    {
        r[i] += s[i] * m;
        for(int j = 0; j < N; ++j)
            if(r[j] > 999999)
                r[j + 1] += r[j] / 1000000, r[j] %= 1000000;
    }
    free(s);
    return r;
}

int main()
{
    int a, i;
    int *d = (int*)calloc(N, sizeof(int));
    FILE *f=fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d", &a);
    d[0] = 1;
    for(i = 2; i <= a; ++i)
        d = mult(d, i);
    for(i = N - 1; d[i] == 0; --i);
    fprintf(q,"%d", d[i]);
    while(--i >= 0)
        fprintf(q,"%06d", d[i]);
    return 0;
}
