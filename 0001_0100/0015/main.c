#include <stdio.h>

int main()
{
    int n, a = 0;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            int k;
            fscanf(f, "%d", &k);
            if (k && j < i)
                ++a;
        }
    fprintf(q, "%d", a);
    return 0;
}
