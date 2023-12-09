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
struct data {
 double value;
 int order;
 int rank;
} list1[10005];
struct data list2[10005];
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

int a[10005],b[10005];
int main()
{
	int n,m;
	scanf("%d",&n);
	F(i,0,n-1){
		scanf("%lf%lf",&list1[i].value,&list2[i].value);
		list1[i].order=i;
		list2[i].order=i;
	}
	qsort(list1,n,sizeof(struct data),cmp1);
	qsort(list2,n,sizeof(struct data),cmp1);
	F(i,0,n-1){
		a[i]=list1[i].order;
		list1[i].rank=i+1;
	}
	F(i,0,n-1){
		b[i]=list2[i].order;
		list2[i].rank=i+1;
	}
	qsort(list1,n,sizeof(struct data),cmp2);
	qsort(list2,n,sizeof(struct data),cmp2);
	F(i,0,n-1){
		m=a[i];
		printf("%d ",list2[m].rank);
	}
	printf("\n");
	F(i,0,n-1){
		m=b[i];
		printf("%d ",list1[m].rank);
	}
	return 0;
}
