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
int cmp1(const void*c,const void*d){
	if(((double*)c)[0]<((double*)d)[0])return -1;
	if(((double*)c)[0]>((double*)d)[0])return 1;
}
int cmp2(const void*c,const void*d){
	if(((double*)c)[1]<((double*)d)[1])return -1;
	if(((double*)c)[1]>((double*)d)[1])return 1;
}
char s[500050][100];
double a[500050][3];
int rank[500050];
int main()
{
	int i=0,n;
	while(scanf("%s",s[i])!=EOF){
		a[i][0]=atof(s[i]);
		a[i][1]=i+1;
		i++;
	}
	n=i;
	qsort(a,n,3*sizeof(double),cmp1);
	rank[0]=1;
	F(j,0,n-1){
		if(j>0){
		if(fabs(a[j][0]-a[j-1][0])<eps)
		a[j][2]=a[j-1][2];
		else
		a[j][2]=j+1;
		}
		else
		a[j][2]=j+1;
		
	}
	qsort(a,n,3*sizeof(double),cmp2);
	printf("%d\n",n);
	F(i,0,n-1){
		rank[i]=(int)a[i][2];
		printf("%d: %s\n",rank[i],s[i]);
		
	}
	return 0;
}
/*struct data {
 double value;
 int order;
 int rank;
 char str[100];
} list[500005];
int cmp1(const void *p1, const void *p2)
{
 if(fabs(((struct data *)p1)->value-((struct data *)p2)->value)<eps) return 0;
 else if(((struct data *)p1)->value>((struct data *)p2)->value) return 1;
 else return -1;
}
int cmp2(const void *p1, const void *p2)
{
 if(((struct data *)p1)->order==((struct data *)p2)->order) return 0;
 else if(((struct data *)p1)->order>((struct data *)p2)->order) return 1;
 else return -1;
}
int main()
{
 int n=0,i;
 while(scanf("%s",list[n].str)!=EOF)
 {
 list[n].order=n+1;
 list[n].value=atof(list[n].str);
 n++;
 }
 printf("%d\n",n);
 qsort(list,n,sizeof(struct data),cmp1);
 list[0].rank=1;
 for(i=1;i<n;i++)
 {
 if(fabs(list[i].value-list[i-1].value)<eps) list[i].rank=list[i-1].rank;
 else list[i].rank=i+1;
 }
 qsort(list,n,sizeof(struct data),cmp2);
 for(i=0;i<n;i++)
 {
 printf("%d: %s\n",list[i].rank,list[i].str);
 }
 return 0;
}*/