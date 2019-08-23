#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n, k;
    char s[21];

    fscanf(f,"%d%s", &n, s);
    k = strlen(s);
    for (int i = n - k; i > 0; i -= k)
        n *= i;
    fprintf(q, "%d", n);
    return 0;
}
