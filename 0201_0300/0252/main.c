#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mass
{
    int num;
    char s[3];
    char r[21];
    int l;
};

int compare(struct mass *a, struct mass *b)
{
    if (a->l < b->l)
        return -1;
    if (a->l > b->l)
        return 1;
    return strcmp(a->r, b->r);
}

void count(struct mass *p)
{
	int n = 0;
	long long d = 1;
	switch(p->s[0])
	{
	case 'g':
		n = 3;
		break;
	case 'k':
		n = 6;
		break;
	case 'M':
	case 't':
		n = 9;
		break;
	case 'G':
		n = 12;
		break;
	case 'p':
		d = 16380000;
		break;
    }
    if (p->s[1] == 'p')
        d *= 16380;
    else if (p->s[1] == 't')
        n += 6;
    for (int i = 0; i < n; ++i)
        p->r[i]='0';
    d *= p->num;
    for(; d; ++n, d /= 10)
        p->r[n] = d % 10 + '0';
    p->r[n] = '\0';
    for (int i = 0; i < n / 2; ++i)
    {
        char c = p->r[i];
        p->r[i] = p->r[n - i - 1];
        p->r[n - i - 1] = c;
    }
    p->l = n;
}

void swap(struct mass *p, int i, int j)
{
    struct mass t = p[i];
    p[i] = p[j];
    p[j] = t;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	struct mass *p;

	fscanf(f, "%d\n", &n);
	p = (struct mass*)malloc(sizeof(struct mass) * n);
	for (int i = 0; i < n; ++i, ++p)
	{
		fscanf(f, "%d %s\n", &(p->num), p->s);
        count(p);
	}
	p -= n;
	for (int i = 0, fin; i < n; ++i)
	{
		fin = 1;
		for (int j = 0; j < n - 1 - i; ++j)
			if (compare(p + j, p + j + 1) > 0)
				swap(p, j, j + 1), fin = 0;
		if (fin)
			break;
	}
	for (int i = 0; i < n; ++i, ++p)
		fprintf(q,"%d %s\n", p->num, p->s);
	return 0;
}
