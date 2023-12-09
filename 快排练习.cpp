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
#define eps 1e-6
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int cmp(const void*c,const void*d){
	if(((int*)c)[0]+((int*)c)[1]<((int*)d)[0]+((int*)d)[1])return 1;
	if(((int*)c)[0]+((int*)c)[1]>((int*)d)[0]+((int*)d)[1])return -1;
	if(fabs(((int*)c)[0]-((int*)c)[1])>fabs(((int*)d)[0]-((int*)d)[1]))return 1;
	if(fabs(((int*)c)[0]-((int*)c)[1])<fabs(((int*)d)[0]-((int*)d)[1]))return -1;
	if(((int*)c)[2]<((int*)d)[2])return -1;
	if(((int*)c)[2]>((int*)d)[2])return 1;
}
int s[5050][3];
int main()
{
	int i=0,n;
	while(scanf("%d%d",&s[i][0],&s[i][1])!=EOF){
		s[i][2]=i;
		i++;
	}
	n=i;
	qsort(s,n,3*sizeof(int),cmp);
	F(j,0,n-1){
		printf("%d %d\n",s[j][0],s[j][1]);
	}
	return 0;
}