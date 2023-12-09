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
#define eps 1e-12
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
struct data {
 double value;
 int time;
 char str[15];
} list[100100];
int cmp(const void *p1, const void *p2)
{
 if(((struct data *)p1)->value>((struct data *)p2)->value) return -1;
 if(((struct data *)p1)->value<((struct data *)p2)->value) return 1;
 else if(fabs(((struct data *)p1)->value-((struct data *)p2)->value)<eps){
 if(((struct data *)p1)->time>((struct data *)p2)->value) return 1;
 if(((struct data *)p1)->time<((struct data *)p2)->value) return -1;
 }
}
int main()
{
 int n=0,i;
 while(scanf("%s%lf%d",list[n].str,&list[n].value,&list[n].time)!=EOF)
 {
 n++;
 }
 qsort(list,n,sizeof(struct data),cmp);
 for(i=0;i<n;i++)
 {
 printf("%10s %8.2lf %10d\n",list[i].str,list[i].value,list[i].time);
 }
 return 0;
}