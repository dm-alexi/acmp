#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int p[5];
	char *s = "Nothing";

	for (int i = 0; i < 5; ++i)
		fscanf(f, "%d", p + i);
	qsort(p, 5, sizeof(int), cmp);
	if (p[0] == p[4])
		s = "Impossible";
	else if (p[0] == p[3] || p[1] == p[4])
		s = "Four of a Kind";
	else if ((p[0] == p[2] && p[3] == p[4]) || (p[0] == p[1] && p[2] == p[4]))
		s = "Full House";
	else if (p[0] + 1 == p[1] && p[1] + 1 == p[2] && p[2] + 1 == p[3] && p[3] + 1 == p[4])
		s = "Straight";
	else if (p[0] == p[2] || p[1] == p[3] || p[2] == p[4])
		s = "Three of a Kind";
	else if((p[0] == p[1] && (p[2] == p[3] || p[3] == p[4])) || (p[1] == p[2] && p[3] == p[4]))
		s = "Two Pairs";
	else if (p[0] == p[1] || p[1] == p[2] || p[2] == p[3] || p[3] == p[4])
		s = "One Pair";
	fprintf(q, "%s", s);
	return 0;
}
