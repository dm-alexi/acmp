#include <stdio.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int t = 0, k;
	char s[100001];

	fscanf(f, "%s", s);
	k = -(s[0] == ')' || s[0] == ']');
	for (int i = 0, n = strlen(s); k >= 0 && i < n; ++i)
		if (s[i] == '(' || s[i] == '[')
			s[t++] = s[i];
		else if (!t)
			k = -1;
		else if (t-- && ((s[i] == ')' && s[t] == '[') || (s[i] == ']' && s[t] == '(')))
			++k;
	fprintf(q, t ? "-1" : "%d", k);
	return 0;
}
