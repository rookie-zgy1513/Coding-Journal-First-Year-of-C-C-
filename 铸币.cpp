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
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int s[35]={0};
void rev(int c[]){
	int hi=0,low=0;
	int temp;
	while(c[hi]!=0){
		hi++;
	}
	for (hi--; hi>low; low++,hi--)//头尾交换，以hi>low作为循环结束的条件，防止循环回去等于没交换，例如一个字符串有五个字符则每次交换（1，5）（2，4），3不交换。
    {
        temp=s[low];
        s[low]=s[hi];
        s[hi]=temp;
    }
}
int main()
{
	int n,i=0,l;
	scanf("%d",&n);
	while(n!=0){
		if(n%2==1){
			s[i]=1;
			n=(n-1)/2;
		}
		else {
			s[i]=2;
			n=(n-2)/2;
		}
		i++;
	}
	rev(s);
	F(i,0,35){
		if(s[i]==0)break;
	printf("%d",s[i]);
	}
	
	return 0;
}