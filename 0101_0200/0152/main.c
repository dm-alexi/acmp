#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
	struct node *id;
	struct edge *next;
} edge;

typedef struct node
{
	edge *e;
	int color;
} node;

int dfs(node *p)
{
	edge *t;

	p->color = 1;
	t = p->e;
	while (t)
	{
		if ((t->id->color == 0 && dfs(t->id) == 1) || t->id->color == 1)
			return 1;
		t = t->next;
	}
	p->color = 2;
	return 0;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, r = 0;
	node *p;
	edge *t;

	fscanf(f, "%d%d", &n, &m);
	p = (node*)calloc(n, sizeof(node));
	for (int i = 0, a, b; i < m; ++i)
	{
		fscanf(f, "%d%d", &a, &b);
		t = p[a - 1].e;
		p[a - 1].e = (edge*)malloc(sizeof(edge));
		p[a - 1].e->id = p + b - 1;
		p[a - 1].e->next = t;
	}
	for (int i = 0; i < n; ++i)
		if (p[i].color == 0 && dfs(p + i) && (r = 1))
			break;
	fprintf(q, r ? "No" : "Yes");
	return 0;
}
