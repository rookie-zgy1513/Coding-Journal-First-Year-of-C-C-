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
#define MAXLENGTH 105
int graph[MAXLENGTH][MAXLENGTH] = {{0}};
int n,m;
int temp[MAXLENGTH] = {0};
int tmp[MAXLENGTH] = {0};
int flag;
void DFS(int x){
	int i=0;
	if(!flag){
		printf("%d",x);
		flag=1;
	}
	else
	printf(" %d",x);
    temp[x] = 1;
    F(i,1,n)
        if (graph[x][i]&&!temp[i])
        DFS(i);	
    return ;
}
void BFS(int p)
{
    int t;
    int i = 0;
    int j = 0;
    int k = 0;
    tmp[1] = p;
    for (i=1,j=1; i<=j;)
    {
        t = tmp[i++];
        if (temp[t])
            continue;
        if (!flag)
        {
            printf("%d", t);
            flag = 1;
        }
        else
            printf(" %d", t);
        temp[t] = 1;
        F(k,1,n)
            if (graph[t][k]&&!temp[k])
                tmp[++j] = k;
    }
}
int main()
{
	int vertex, edge,d;
    int i = 0;
    scanf("%d%d",&n,&m);
	F(i,1,m){
		scanf("%d%d", &vertex, &edge);
		graph[vertex][edge] = 1;
        graph[edge][vertex] = 1;
	}
	DFS(0);
    printf("\n");
    memset(temp, 0, sizeof(temp)/temp[0]);
    flag = 0;
    BFS(0);
    printf("\n");
    memset(temp, 0, sizeof(temp)/temp[0]);
    flag = 0;
	scanf("%d",&d);
    temp[d] = 1;
    DFS(0);
    printf("\n");
    memset(temp, 0, sizeof(temp)/temp[0]);
    flag = 0;
    temp[d] = 1;
    BFS(0);
    printf("\n");
	return 0;	
}