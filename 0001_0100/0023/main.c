#include <stdio.h>

int main()
{
    int n, s = 0;
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%d", &n);
    for (int i = 1; i <= n / 2; ++i)
        if(!(n % i))
            s += i;
    fprintf(q, "%d", s + n);
    return 0;
}
