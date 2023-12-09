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
char s[250];
char var[55][50];
int cmp(const void*c,const void*d){
	return strcmp(((char*)c),((char*)d));
}
int main()
{
	int l,j=0,k=0,n;
	gets(s);
	l=strlen(s);
	F(i,0,l-1){
		if(isalnum(s[i])||s[i]=='_'){
			var[j][k]=s[i];
			k++;
		}
		else if(k){
			var[j][k]='\0';
			j++;
			k=0;
		}
	}
	n=j;
	qsort(var,n,sizeof(var[0]),cmp);
	F(i,0,n-1)
	F(j,0,i-1){
		if(!strcmp(var[i],var[j])){
			strcpy(var[i],"\0");
		}
	}
	F(i,0,n-1){
		k=0;
		l=strlen(var[i]);
		F(j,0,l-1){
			if(isdigit(var[i][j]))
			k++;
		}
		if(k==l)
		strcpy(var[i],"\0");
	}
	F(i,0,n-1){
		if(strlen(var[i]))
		printf("%s ",var[i]);
	}
	return 0;
}