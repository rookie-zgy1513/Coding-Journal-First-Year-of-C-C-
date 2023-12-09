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
char s[110][1010];
int main()
{
	int n,m,min=1010;
	int cnt=0;
	scanf("%d%d",&n,&m);
	F(i,1,m){
		scanf(" %s",s[i]);}
		F(i,1,m){
			F(j,i+1,m){
				cnt=0;
				F(k,0,n-1){
					if((s[i][k]-'0')^(s[j][k]-'0'))
					cnt++;
				}
				if(cnt<min)
				min=cnt;
			}
			
		}
		printf("%d",min);
		return 0;
}