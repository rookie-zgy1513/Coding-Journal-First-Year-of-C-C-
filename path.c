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
#define MAXNUMBER 1000
typedef struct edge{
    int id;
    int adj;
    int weight;
    struct edge *next;
}Edge,*EdgePtr;
typedef struct vertex{
    int num;
    EdgePtr next;
}Vertex,*VertexPtr;
Vertex graph[MAXNUMBER];
int visit[MAXNUMBER];
int path[MAXNUMBER];
int num_vertex,num_edge;
int depth = 0;
int id;
int start,end;
EdgePtr insert_edge(EdgePtr head, int id, int num)
{
    EdgePtr e,p;
    e = (EdgePtr)malloc(sizeof(Edge));
    e->id = id;
    e->adj = num;
    e->weight = 1;
    e->next = NULL;
    if (head==NULL)
        head = e;
    else
    {
        for (p=head; p->next!=NULL; p=p->next);
        p->next = e;
    }
    return head;
}
void output(int n)
{
    int i = 0;
    for (i=0; i<n; i++)
    {
        printf("%d ",path[i]);
    }
    printf("\n");
    return ;
}
void DFS(int v, int depth)
{
    EdgePtr p;
    if (v==end)
    {
        output(depth);
        return;
    }
    for (p=graph[v].next; p!=NULL; p=p->next)
    {
        if (!visit[p->adj])
        {
            path[depth] = p->id;
            visit[p->adj] = 1;
            DFS(p->adj, depth+1);
            visit[p->adj] = 0;
        }
    }
}
int main()
{
	int i = 0;
	int v1,v2;
	scanf("%d %d",&num_vertex,&num_edge);
    start = 0;
    end = num_vertex-1;
    F(i,0,num_edge-1)
    {
        scanf("%d %d %d",&id,&v1,&v2);
        graph[v1].next = insert_edge(graph[v1].next, id, v2);
        graph[v2].next = insert_edge(graph[v2].next, id, v1);
    }
	visit[start] = 1;
    DFS(start, depth);
	return 0;
}