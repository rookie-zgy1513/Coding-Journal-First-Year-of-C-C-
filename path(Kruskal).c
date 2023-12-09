#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define FD(i,l,r) for(int i=(l);i<(r);i++)
#define SWAP(a,b) x^=y,y^=x,x^=y
#define eps 1e-8
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
#define MAXSIZE 500
typedef struct edge{
    int id;
    int start;
    int end;
    int weight;
}Edge,*EdgePtr;
Edge edges[MAXSIZE];
int set[MAXSIZE];
int path[MAXSIZE];
int sum = 0;
int cmp1(const void *p1, const void *p2)
{
    Edge *a = (Edge *)p1;
    Edge *b = (Edge *)p2;
    if (a->weight!=b->weight)
        return a->weight-b->weight;
    else
        return 0;
}
int cmp2(const void *p1, const void *p2)
{
    return *(int *)p1-*(int *)p2;
}
void kruskal(Edge e[], int n, int edge)
{
    int i = 0,j = 0;
    int k = 1;
    int s1,s2;
    for (i=1; i<=n; i++)
        set[i] = i;
    while (k<=edge)
    {
        s1 = set[e[j].start];
        s2 = set[e[j].end];
        if (s1!=s2)
        {
            path[k] = e[j].id;
            sum+=e[j].weight;
            k++;
            if (k>=n)
                break;
            for (i=1; i<=n; i++)
                if (set[i]==s2)
                    set[i] = s1;
        }
        j++;
    }
    
}
int main()
{
	int num_vertex,num_edge;
    scanf("%d %d",&num_vertex,&num_edge);
    int i = 0;
    F(i,0,num_edge)
	{
        scanf("%d %d %d %d",&edges[i].id,&edges[i].start,&edges[i].end,&edges[i].weight);
    }
	qsort(edges, num_edge, sizeof(edges[0]), cmp1);
	kruskal(edges, num_vertex, num_edge);
	printf("%d\n",sum);
    qsort(path, num_vertex, sizeof(int), cmp2);
    for (i=1; i<num_vertex; i++)
    {
        printf("%d ",path[i]);
    }
    return 0;
}