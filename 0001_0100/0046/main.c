#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n;
    char s[] = "2.7182818284590452353602875";

    fscanf(f, "%d", &n);
    if (!n)
        s[0] = '3', s[1] = '\0';
    else if (n < 25 && s[n + 2] >= '5')
        ++s[n + 1];
    s[n + 2] = '\0';
    fprintf(q, s);
    return 0;
}
