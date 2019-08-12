#include <stdio.h>
 
int main()
{
    long a;
 
    FILE *f=fopen("input.txt", "r");
    fscanf(f, "%ld", &a);
    fclose(f);
 
    a/=10;
    a=a*(a+1);
 
    f=fopen("output.txt", "w");
    if(a>0)
        fprintf(f,"%ld", a);
    fprintf(f, "25");
    return 0;
}