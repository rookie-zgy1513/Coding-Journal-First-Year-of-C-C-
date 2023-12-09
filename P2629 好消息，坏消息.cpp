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
#define MAXNUM 2000005
long long a[MAXNUM];
long long s[MAXNUM];
long long q[MAXNUM];
int n,head=1,tail;
/*int check(int now){
	for(int m=0;m<n;m++){
		if(s[now+m]-s[now-1]<0) return 0;
	}
	return 1;
}*/
int main()
{
	int flag=0,i,j;
	long long ans=0;
	int num;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i+n]=a[i];
		s[i]=s[i-1]+a[i];
	}
	j=1;
	for(i=n+1;i<=2*n-1;i++){
		s[i]=s[i-1]+a[j];
		j++;
	}
	for(i=1;i<=2*n-1;i++){
		while(head<=tail&&MAX(i-n+1,1)>q[head])
		head++;
        while(head<=tail&&s[i]<=s[q[tail]])
		tail--;
        q[++tail]=i;
        if(i-n+1>0&&s[q[head]]-s[i-n]>=0)
		ans++;
	}
	/*for(int i=1;i<=n;i++){
		if(check(i)) ans++;
	}*/
	printf("%lld",ans);
	return 0;
}