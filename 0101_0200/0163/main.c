#include <stdio.h>

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int n;
    char s[5];

    fscanf(f, "%s", s);
    if (s[4] == 'x')
		n = (s[1] == '+') ? s[0] + s[2] - 2 * '0' : s[0] - s[2];
    else if (s[0] == 'x')
        n = (s[1] == '+') ? s[4] - s[2] : s[4] + s[2] - 2 * '0';
    else
		n = (s[1] == '+') ? s[4] - s[0] : s[0] - s[4];
	fprintf(q, "%d", n);
    return 0;
}
