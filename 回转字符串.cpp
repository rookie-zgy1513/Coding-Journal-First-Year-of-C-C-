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
char str[2010];
char str1[2010];
char str2[2010];
char str3[2010];
int main()
{
	int l,cnt=0,k,m,L,j;
	scanf("%s",str);
	scanf("%d",&k);
	
	l=strlen(str);
	F(i,0,l-1){
		m=0;j=i;L=k;
	    while(L>0){
	    	if(j>=l)
	    	j=j%(l);
	       str1[m]=str[j];
			m++;j++;L--;
		}
		str1[k]=0;L=k;	
		for(int p=0;p<L;p++){
			str2[p]=str1[L-p-1];
		}
		if(!strcmp(str1,str2))
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}



