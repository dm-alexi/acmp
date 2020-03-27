#include <stdio.h>
#include <string.h>

int checkstr(char *s)
{
	int j = 0;

	if (strlen(s) % 2)
		return 0;
	for (int i = 0; s[i]; ++i)
		if (j && ((s[i] == ')' && s[j - 1] == '(') || (s[i] == ']' && s[j - 1] == '[') || (s[i] == '}' && s[j - 1] == '{')))
			--j;
		else if (j && ((s[i] == ')' && (s[j - 1] == '[' || s[j - 1] == '{')) || (s[i] == ']' && (s[j - 1] == '(' || s[j - 1] == '{')) || (s[i] == '}' && (s[j - 1] == '[' || s[j - 1] == '('))))
			return 0;
		else
			s[j++] = s[i];
	for (int i = 0; i < j / 2; ++i)
		if (!((s[i] == ')' && s[j - 1 - i] == '(') || (s[i] == ']' && s[j - 1 - i] == '[') || (s[i] == '}' && s[j - 1 - i] == '{')))
			return 0;
	return 1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char s[10001];

	fscanf(f, "%s", s);
	fprintf(q, checkstr(s) ? "YES" : "NO");
	return 0;
}
