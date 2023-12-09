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
struct stu{
	char name[25];
	int num;
	double val;
}rank[10005];
int cmp(const void *p1, const void *p2)
{
 
 if(((struct stu *)p1)->val>((struct stu *)p2)->val) return -1;
 if(((struct stu *)p1)->val<((struct stu *)p2)->val) return 1;
 if(fabs(((struct stu *)p1)->val-((struct stu *)p2)->val)<eps){
  if(((struct stu *)p1)->num>((struct stu *)p2)->num) return 1;
 else if(((struct stu *)p1)->num<((struct stu *)p2)->num) return -1;
 else {
    return strcmp(((struct stu *)p1)->name, ((struct stu *)p2)->name); //返回两个字符串的字典序大小
 }
 };
}
int main()
{
	int n;
	scanf("%d",&n);
	F(i,0,n-1)
	scanf("%s%08d%lf",rank[i].name,&rank[i].num,&rank[i].val);
	qsort(rank,n,sizeof(struct stu),cmp);
	F(i,0,n-1){
		printf("%s %08d %.4lf\n",rank[i].name,rank[i].num,rank[i].val);
	}
	return 0;
}