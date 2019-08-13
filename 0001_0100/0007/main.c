#include <stdio.h>
#include <string.h>

char *comp(char *a, char *b)
{
    char *s = a, *t = b;
    int m=strlen(s), n=strlen(t);
    if (m != n)
        return m > n ? a : b;
    for (; *s && *s == *t; ++s, ++t);
    return *s - *t >= 0 ? a : b;
}

int main()
{
    char s1[102], s2[102], s3[102];

    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    fscanf(f, "%s %s %s", s1, s2, s3);
    fprintf(q, "%s", comp(s1, comp(s2, s3)));
    return 0;
}
