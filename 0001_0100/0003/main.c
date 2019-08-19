#include <stdio.h>
 
int main()
{
    long a; 
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");

    fscanf(f, "%ld", &a); 
    a /= 10;
    a = a * (a + 1);
    if (a > 0)
        fprintf(q, "%ld", a);
    fprintf(q, "25");
    return 0;
}