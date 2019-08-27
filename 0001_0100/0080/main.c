#include <stdio.h>
#include <stdlib.h>

int getnum(char *s, int *n)
{
    int i = 0;
    if (s[i] == '-')
        ++i;
    while(s[i] >= '0' && s[i] <= '9')
        ++i;
    if (s[0] == '-' && i == 1)
        return 0;
    *n = atoi(s);
    return i;
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    int a, b, c, t, g, k;
    const char *ans = "ERROR";
    char s[101], op;

    for (k = 0; (s[k] = fgetc(f)) != EOF && s[k] != '\n'; ++k);
    s[k] = '\0';
    if ((t = getnum(s, &a)) && ((op = s[t]) == '+' || op == '-' || op == '/' || op == '*')
        && (g = getnum(s + t + 1, &b)) && s[t + g + 1] == '=' && (k = getnum(s + t + g + 2, &c)) && !s[t + g + k + 2])
    {
        a = op == '+' ? a + b : op == '-' ? a - b : op == '*' ? a * b : op == '/' && b && !(a % b) ? a / b : c + 1;
        ans = a == c ? "YES" : "NO";
    }
    fprintf(q, ans);
    return 0;
}
