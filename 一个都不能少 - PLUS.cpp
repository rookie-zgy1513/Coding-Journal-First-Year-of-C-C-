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
int a[1000005];
int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2; 
 
}

int main()
{
	int n,x,first=-2147483647,last=2147483647,flag=0;
	long long ans=0,Ans=1;
	scanf("%d",&n);
	F(i,0,n-1){
		scanf("%d",&x);
		a[i]=x;
		if(x>first)
		first=x;
		if(x<last)
		last=x;
		ans=ans^x;
	}
	if(n%2){
		printf("1 %lld",ans);
	}
	else{
		if(!ans){
			printf("%d %d",last,first);
		}
		else{
			qsort(a,n,sizeof(int),cmp);
			ans=0;
			F(i,0,n-1){
				ans=ans^a[i];
				if(ans==a[i]||ans==0)continue;
				Ans=Ans*a[i-1];
				flag++;
				ans=a[i];
			}
			if(flag==1){
				Ans=Ans*a[n-1];
				printf("2 %lld",Ans);
			}
			else
			printf("2 %lld",Ans);
		}
	}
	return 0;
}
/*int main()
{
	int n;
	long long ans=0,Ans=1;
	scanf("%d",&n);
	F(i,0,n-1){
	scanf("%d",&a[i]);
	ans=ans^a[i];
	}
	qsort(a,n,sizeof(int),cmp);
	if(n%2){
		printf("1 %lld",ans);
	}
    else if(!ans){
		printf("%d %d",a[0],a[n-1]);
	}
	
	else{
		F(i,0,n){
			if(i==0){
				if(a[i]!=a[1])
				Ans=Ans*a[i];
			}
			else if(i==n-1){
				if(a[i]!=a[n-2])
				Ans=Ans*a[i];
			}
			else{
				if(a[i]!=a[i+1]&&a[i]!=a[i-1])
				Ans=Ans*a[i];
			}
		}
		printf("2 %lld",Ans);
	}
	return 0;
}*/