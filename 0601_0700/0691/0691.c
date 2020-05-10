#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	char s[301];
	const char *t = "ABCEHKMOPTXY";

	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%s", s);
		fprintf(q, strlen(s) == 6 && strchr(t, s[0]) && strchr(t, s[4]) && strchr(t, s[5]) && isdigit(s[1]) && isdigit(s[2]) && isdigit(s[3]) ? "Yes\n" : "No\n");
	}
	return 0;
}
