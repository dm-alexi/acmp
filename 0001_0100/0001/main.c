#include <stdio.h>
 
int main()
{
    long a, b;
 
    FILE *f=fopen("input.txt", "r");
    fscanf(f, "%ld %ld", &a, &b);
    fclose(f);
    f=fopen("output.txt", "w");
    fprintf(f, "%ld", a+b);
    return 0;
}