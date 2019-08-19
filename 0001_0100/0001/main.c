#include <stdio.h>
 
int main()
{
    long a, b;
 
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    fscanf(f, "%ld%ld", &a, &b);
    fprintf(q, "%ld", a + b);
    return 0;
}