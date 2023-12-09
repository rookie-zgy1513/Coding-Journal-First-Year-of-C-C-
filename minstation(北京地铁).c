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
#define MAXLENGTH 25
#define MAXSTATION 512
#define INF 32767
typedef struct station{
    char name[MAXLENGTH];
    int is_transfer;
}sta;
sta stations[MAXSTATION];
typedef struct edg{
    int weight;
    int line;
}edg;
edg vertex[MAXSTATION+2][MAXSTATION+2];
int path[MAXSTATION];
void Dijkstra(int origin,int destination)
{
    int i = 0,j = 0;
    int v = 0;
    int min;
    int find[MAXSTATION] = {0};
    int min_dis[MAXSTATION] = {0}; // 存最短距离
    for(i=1; i<=MAXSTATION; i++)
    {
        min_dis[i] = vertex[origin][i].weight;
        path[i] = origin;
    }
    min_dis[origin] = 0;
    find[origin] = 1;
    for(i=1; i<MAXSTATION; i++)
    {
        min = INF;
        for(j=1; j<=MAXSTATION; j++)
        {
            if(!find[j]&&min_dis[j]<min)
            {
                min = min_dis[j];
                v = j;
            }
        }
        find[v] = 1;
        if(v==destination)
            return;
        for(j=1; j<=MAXSTATION; j++)
        {
            if(!find[j]&&vertex[v][j].line>0&& min+vertex[v][j].weight<min_dis[j])
            {
                min_dis[j] = min+vertex[v][j].weight;
                path[j] = v;
            }
        }
    }
}

int main()
{
	FILE *fp;
    fp = fopen("bgstations.txt","r");
	int max_line;
    fscanf(fp,"%d",&max_line);
    int i = 1,j = 1;
    int k = 0,l = 0;
    int v1,v2;
    int num_line,num_station;
    int transfer;
    for(i=1; i<=MAXSTATION; i++)
    {
        for(j=1;j<MAXSTATION;j++)
        {
            vertex[i][j].weight = INF;
            vertex[i][j].line = 0;
        }
    }//初始化
    F(i,1,max_line)
    {
        v1 = v2 = -1;
        fscanf(fp,"%d%d",&num_line,&num_station);
        F(j,1,num_station)
        {
            char name[MAXSTATION];
            int flag = 1;
            fscanf(fp,"%s%d",name,&transfer);
            F(k,1,l)
            {
                if(strcmp(stations[k].name,name)==0)
                {
                    flag = 0;
                    v1 = k;
                    break;
                }
            }
            if(flag)
            {
                l++;
                strcpy(stations[l].name,name);
                stations[l].is_transfer = transfer;
                v1 = l;
            }
            if(v2!=-1)
            {
                vertex[v1][v2].line=vertex[v2][v1].line = num_line;
                vertex[v1][v2].weight = vertex[v2][v1].weight = 1;
            }
            v2 = v1;
        }
    }//完成文件的读入以及初始化
	char start[MAXLENGTH],end[MAXLENGTH];
    scanf("%s%s",start,end);
    int starting = 0,destination = 0;
    int count = 0;
    for(i=1; i<=l; i++)
    {
        if(strcmp(stations[i].name,start)==0)
        {
            starting = i;
            count++;
        }
        if(strcmp(stations[i].name,end)==0)
        {
            destination = i;
            count++;
        }
        if(count==2)
            break;
    }
	Dijkstra(starting,destination);
	 i = destination,j = 1;
    int rev[MAXSTATION] = {0};
    int flag = 0;
     count = 1;
    rev[0] = destination;
    while (i!=starting)
    {
        rev[j++] = path[i];
        i = path[i];
    }
    for(i=j-1; i>0; i--)
    {
        if(!flag)
        {
            printf("%s-%d",stations[rev[i]].name,vertex[rev[i]][rev[i-1]].line);
            flag = 1;
        }
        else
        {
            if(vertex[rev[i+1]][rev[i]].line==vertex[rev[i]][rev[i-1]].line)
            {
                count++;
            }
            else
            {
                printf("(%d)-",count);
                count = 1;
                flag = 0;
                i++;
            }
        }
    }
    printf("(%d)-%s\n",count,stations[destination].name);
	fclose(fp);
    return 0;
}