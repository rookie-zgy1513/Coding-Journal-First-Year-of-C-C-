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
char s[210][1010];
int l[210];
int main()
{
	int j=0;
	char*p1,*p2;
	while(fgets(s[j],1010,stdin)!=NULL){
		p1=s[j];
		while((strstr(p1,"begin"))!=NULL){p2=strstr(p1,"begin");
			*p2=123;
			F(i,1,4){
				*(p2+i)='#';
			}
			p1=p2+5;
		}
	
	p1=s[j];
	while((strstr(p1,"end"))!=NULL){
	p2=strstr(p1,"end");
			*p2=125;
			F(i,1,2){
				*(p2+i)='#';
			}
			p1=p2+3;
	}
	l[j]=strlen(s[j]);	
	j++;	
	}
	F(i,0,j-1){
	F(k,0,l[i]){
		if(s[i][k]=='#'){
			k++;continue;
		}
		printf("%c",s[i][k]);
	}
	}
	
	
	return 0;
} 