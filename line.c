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
struct coordinates{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
}lines[105];
int cmp1(const void *p1, const void *p2)
{
    struct coordinates *a = (struct coordinates*)p1;
    struct coordinates *b = (struct coordinates*)p2;
    if (a->x1 < b->x1)
        return -1;
    if (a->x1 > b->x1)
        return 1;
    if (a->x1==b->x1)
    {
        if (a->y1 < b->y1)
            return -1;
        if (a->y1 > b->y1)
            return 1;
    }
    return 0;
}
int cmp2(const void *p1, const void *p2)
{
    struct coordinates *a = (struct coordinates*)p1;
    struct coordinates *b = (struct coordinates*)p2;
    if (a->count > b->count)
        return -1;
    if (a->count < b->count)
        return 1;
    return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	F(i,0,n-1){
        scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
        lines[i].count = 1;
    }
    qsort(lines,n,sizeof(struct coordinates),cmp1);//快排一遍，方便遍历
    F(i,0,n-1)
    {
        int k = i;
        F(j,i+1,n-1)
        {
            if (lines[k].x2==lines[j].x1&&lines[k].y2==lines[j].y1)
            {
                lines[i].count++;
                k = j;
            }
        }
    }
    qsort(lines,n,sizeof(struct coordinates),cmp2);//选出最大的
	printf("%d %d %d",lines[0].count,lines[0].x1,lines[0].y1);
    return 0;
}