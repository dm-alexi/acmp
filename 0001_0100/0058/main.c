#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, a, b, *p1, *p2;

    fscanf(f, "%d", &n);
    while (n--)
    {
        char *s = "YES\n";
        fscanf(f, "%d%d", &a, &b);
        p1 = (int*)malloc(sizeof(int) * b);
        for (int i = 0; i < b; ++i)
            fscanf(f, "%d", p1 + i);
        for (int i = 1; i < a; ++i)
        {
            p2 = (int*)malloc(sizeof(int) * b);
            for (int j = 0; j < b; ++j)
                fscanf(f, "%d", p2 + j);
            for (int j = 1; j < b; ++j)
                if ((p2[j] && p2[j - 1] && p1[j] && p1[j - 1]) || !(p2[j] || p2[j - 1] || p1[j] || p1[j - 1]))
                {
                    s = "NO\n";
                    break;
                }
            free(p1);
            p1 = p2;
        }
        free(p1);
        fprintf(q, s);
    }
    return 0;
}
