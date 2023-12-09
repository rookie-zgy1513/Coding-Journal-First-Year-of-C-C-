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
struct Node{
    int id;
    char name[16];
    int machine;
    char time[7];
}loginfo[205];
int cmp(const void * c, const void * d){
    struct Node *a = (struct Node*)c;
    struct Node *b = (struct Node*)d;
    if(a->id!=b->id)
        return a->id - b->id;
    else
        return strcmp(a->time,b->time);
}
int main()
{
	int i,j,flag=0;
	int n;
	scanf("%d",&n);
	F(i,0,n-1)
	scanf("%d %s %d %s", &loginfo[i].id, loginfo[i].name, &loginfo[i].machine, loginfo[i].time);
	qsort(loginfo,n,sizeof(struct Node),cmp);
	for(i=0;i<n;){
		flag=0;
		for(j=i+1;j<n&&loginfo[j].id==loginfo[i].id;j++){
			if(loginfo[j].machine!=loginfo[i].machine){
				if(!flag){
					printf("%d %s\n",loginfo[i].id,loginfo[i].name);
					flag++;
				}
			}
		}
		i=j;
	}
	return 0; 
}