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
struct station{
	char name[200];
	int dis;
}a[200];
struct stack{
	char NUM[200]; 
	int dis;
}s[200];
int main()
{
	int n,m,cnt=0;
	int max=10001,maxnum;
	char findname[200];
	scanf("%d",&n);
	F(i,1,n){
		scanf("%s%d",a[i].name,&a[i].dis);
	}
	scanf("%d",&m);
	F(i,0,m-1){
		scanf("%s%s",s[i].NUM,findname);
		F(j,1,n){
			if(!strcmp(findname,a[j].name)){
				s[i].dis=a[j].dis;
			}
		}
	}
	while(m>0){
		max=s[0].dis;
		maxnum=0;
		F(i,0,m-1){
			if(s[i].dis>max){
				max=s[i].dis;
				maxnum=i;
			}
		}
		if(maxnum==0){
			cnt++;
		}
		else
		cnt=cnt+maxnum+2;
		printf("%s ",s[maxnum].NUM);
		F(i,maxnum,m-1){
			s[i].dis=s[i+1].dis;
			strcpy(s[i].NUM,s[i+1].NUM);
		}
		m--;
	}
	printf("\n%d",cnt);
	return 0;
}