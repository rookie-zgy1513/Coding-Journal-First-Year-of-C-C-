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
char s1[1010],s2[1010];
int a[1010],b[1010];
int ans[10001]={0};
int main(){
	int i,j;
    int len1,len2;
	scanf("%s",s1);
	scanf("%s",s2);
	len1=strlen(s1);
	len2=strlen(s2);
	j=0;
	for(i=len1-1;i>=0;i--){
		a[j++]=s1[i]-'0';
	}
	j=0;
	for(i=len2-1;i>=0;i--){
		b[j++]=s2[i]-'0';
	}
	for(i=0;i<=len1-1;i++){
		for(j=0;j<=len2-1;j++){
			ans[i+j]+=a[i]*b[j];
		}
	}
	for(i=0;i<2500;i++){
		if(ans[i]>=10){
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
		}
	}
	for(i=2500;i>=0;i--){
		if(ans[i]!=0){
			for(j=i;j>=0;j--){
		        printf("%d",ans[j]);
			}
			break;
		}
	}
	if(i==-1)
	printf("0");
	return 0;
}