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
struct node{
	int add;    
    int length; 
    int flag;
}space[105];
int main()
{
	int n,m,now=0,next,op;
	int min=0x3fffffff;
	scanf("%d",&n);
	F(i,0,n-1){
	scanf("%d%d",&space[i].add,&space[i].length);
	space[i].flag=1;
	}
	while(scanf("%d",&m)!=-1){
		next=-1;
		int min=0x7fffffff;
		if(m==-1)break;
		F(i,0,n-1){
		op=(now+i)%n;
		if(space[op].length>=m&&space[op].length<min&&space[op].flag==1){
                next=op;
                min=space[op].length;
            }
		}
        if(next==-1)continue;
        else{
			if(space[next].length-m){
            	space[next].length-=m;
            	now=next;
			}
			else{
            	space[next].flag=0;
            	now=(next+1)%n;
			}
	   	  } 
		
	}
	F(i,0,n-1){
		op=(now+i)%n;
		if(space[op].flag){
            printf("%d %d\n",space[op].add,space[op].length);
        }
	}
	return 0;
}