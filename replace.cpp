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
char in[50],out[50];
char text[100000],t[100000];//t转小写
int l1,l2;
void lower(char *s)
{
    int i = 0;
    for (i=0; i<strlen(s); i++)
    {
        s[i]=tolower(s[i]);
    }
}
int mystrstr(int a,char*s){
	int b=0;
	FD(b,0,strlen(s)){
		if(t[a+b]!=s[b])return 0;
	}
	return 1;
}
void replace(int i, char *s)
{
    int j = 0;
    for (j=0; j<strlen(s); j++)
    {
        text[j+i]=out[j];
    }
}
int main()
{
	FILE *fp1,*fp2;
	fp1 = fopen("filein.txt", "r");
    fp2 = fopen("fileout.txt", "w");
	char c;
	int i=0,j=0,l;
	gets(in);gets(out);
	l1=strlen(in);l2=strlen(out);
	while ((c=fgetc(fp1))!=EOF)
    {
        text[i]=t[i]=c;
        i++;
    }
    l=i;
	lower(t);
	FD (i,0,strlen(t))
    {
        if (mystrstr(i, in))
        {
            FD(j,i+l1,l)
            text[j]=text[j+l2-1];
			replace(i, out);
        }
    }
	for (i=0; i<strlen(text); i++)
    {
        fputc(text[i], fp2);
    }
	fclose(fp1);
    fclose(fp2);
    return 0;
}