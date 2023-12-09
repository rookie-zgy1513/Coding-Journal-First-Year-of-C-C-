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
char s[500050];
int main()
{
	char*p1,*p2,*p3,*p;
	int l,a,b,c;
	scanf("%s",s);
	p=s;
	l=strlen(s);
	while(1){
		if(strchr(p,'r')==NULL&&strchr(p,'R')==NULL)break;
		else if(strchr(p,'r')!=NULL&&strchr(p,'R')!=NULL){
			if(strchr(p,'r')-s>strchr(p,'R')-s)
			p1=strchr(p,'R');
			else
			p1=strchr(p,'r');
		}
		else if(strchr(p,'R')==NULL)
		p1=strchr(p,'r');
		else if(strchr(p,'r')==NULL)
		p1=strchr(p,'R');
		if(strchr(p1,'e')==NULL&&strchr(p1,'E')==NULL)break;
		else if(strchr(p1,'e')!=NULL&&strchr(p1,'E')!=NULL){
			if(strchr(p1,'e')-s>strchr(p1,'E')-s)
			p2=strchr(p1,'E');
			else
			p2=strchr(p1,'e');
		}
		else if(strchr(p1,'E')==NULL)
		p2=strchr(p1,'e');
		else if(strchr(p1,'e')==NULL)
		p2=strchr(p1,'E');
		if(strchr(p2,'x')==NULL&&strchr(p2,'X')==NULL)break;
		else if(strchr(p2,'x')!=NULL&&strchr(p2,'X')!=NULL){
			if(strchr(p2,'x')-s>strchr(p2,'X')-s)
			p3=strchr(p2,'X');
			else
			p3=strchr(p2,'x');
		}
		else if(strchr(p2,'X')==NULL)
		p3=strchr(p2,'x');
		else if(strchr(p2,'x')==NULL)
		p3=strchr(p2,'X');
		p=p1+1;
		a=p1-s;b=p2-s;c=p3-s;
		s[a]='0';s[b]='0';s[c]='0';
	}
	F(i,0,l-1){
		if(s[i]!='0')
		printf("%c",s[i]);
	}
	return 0;
}