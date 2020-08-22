#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(char **a, char **b)
{
	return strcmp(*a, *b);
}
 
int search(char **arr, char *s, int l, int r)
{
    if (l > r)
        return 0;
    int k = strcmp(s, arr[(r + l) / 2]);
    if (k == 0)
        return 1;
    return k < 0 ? search(arr, s, l, (r + l) / 2 - 1) : search(arr, s, (r + l) / 2 + 1, r);
}
 
int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
    char t[101];
    char *lines[239];
    int n = 0, m = 0;
 
    fscanf(f, "%s", t);
    while (strcmp(t, "ENDOFINPUT"))
    {
        lines[n++] = strdup(t);
        fscanf(f, "%s", t);
    }
    qsort(lines, n, sizeof(char*), (int(*)(const void*, const void*))comp);
    for (int i = 1; i < n; ++i)
    {
		int found = 0, k = strlen(lines[i]);
        for (int j = i - 1, l; j >= 0 && !found; --j)
            found = (l = strlen(lines[j])) <= k && !(strncmp(lines[i], lines[j], l)) && search(lines, lines[i] + l, 0, n - 1);
        m += found;
    }
    fprintf(q, "%d", m);
    return 0;
}