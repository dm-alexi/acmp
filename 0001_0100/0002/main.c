#include <stdio.h>

int main()
{
    long a;
    FILE *f=fopen("input.txt", "r");
    fscanf(f, "%ld", &a);
    fclose(f);
    f=fopen("output.txt", "w");
    fprintf(f,"%ld", a > 0 ? (1 + a)*a/2 : (1 - a)*a/2 + 1);
    return 0;
}
