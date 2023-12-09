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
char str[10005],s[10005],temp[10005];
int main()
{
	int op,i,l,j,cnt=0;
	char*p;
	char*q;
	char*m;
	p=str;
	scanf("%s",str);
	while(scanf("%d",&op)!=-1){
		if(op==-1)
		break;
		switch(op){
			case 1:
				scanf("%s",s);
				strcat(str,s);
			break;
			case 2:
				scanf("%d",&i);
				strcpy(i+p,"\0");	
			break;
			case 3:
				scanf("%d",&i);
				scanf("%s",s);
				l=strlen(s);
				strcpy(temp,i+p);
				strcpy(i+p,s);
				strcpy(p+i+l,temp);
			break;
			case 4:
				scanf("%d%d",&i,&j);
				strcpy(temp,p+j+1);
				strcpy(i+p,"\0");
				strcpy(i+p,temp);
			break;
			case 5:
				scanf("%d",&i);
				scanf("%s",s);
				l=strlen(s);
				if(strlen(str)>i+l){
					strcpy(temp,i+l+p);
					strcpy(i+p,s);
					strcpy(i+p+l,temp);
				}
				else
				strcpy(i+p,s);
			break;
		}

	}
	scanf("%s",s);
	while((m=strstr(p,s))!=NULL){
		cnt++;
		p=m;
		if((q=strchr(++p,s[0]))!=NULL)
		p=q;
	}
	printf("%d\n%s",cnt,str);
	return 0;
}
