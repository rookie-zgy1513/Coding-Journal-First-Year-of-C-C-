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
char s[200];
int a[50]={0},b[50][4];
int main()
{
	int l,m;
	scanf("%s",s);
	l=strlen(s);
	F(i,0,l-1){
		m=s[i]-'a';
		a[m]++;
		switch(a[m]){
			case 1:
			b[m][1]=i+1;break;
			case 2:
			b[m][2]=i+1;break;
			case 3:
			b[m][3]=i+1;break;
		}
		if(a[m]==3)break;
	}
	printf("%c %d %d %d",'a'+m,b[m][1],b[m][2],b[m][3]);
	return 0;
}