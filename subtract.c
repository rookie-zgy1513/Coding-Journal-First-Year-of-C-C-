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
char s1[100],s2[100];
int a[100],b[100],ans[100];
void delete_zero(char *s)
{
    int i = 0, j = 0, k = 0;
    for (i=0; i<strlen(s); i++)
    {
    	if(i==strlen(s)-1){
    		j=i;
    		break;
		}
        if (s[i]!='0')
        {
            j=i;
            break;
        }
    }
    for (i=j; i<strlen(s); i++)
    {
        s[k++]=s[i];
    }
    s[k]='\0';
}
int main()
{
	int flag=0,l,l1,l2,f1=1,f2=1,j=0,i;
	gets(s1);gets(s2);
	l1=strlen(s1);l2=strlen(s2);
	/*F(i,0,l1-1){
		if(s1[i]!='0'){
		f1=0;
		}
	}
	if(f1){
		s1[0]='0';
		F(i,1,l1-1)
		s1[i]='\0';
	}
	else*/
	delete_zero(s1);
	/*F(i,0,l2-1){
		if(s2[i]!='0'){
		f2=0;
		}
	}
	if(f2){
		s2[0]='0';
		F(i,1,l2-1)
		s2[i]='\0';
	}
	else*/
	delete_zero(s2);
	l1=strlen(s1);l2=strlen(s2);
	if(strcmp(s1,s2)==0)
	printf("0");
	else{
	if(l1<l2||(l1==l2&&strcmp(s1,s2)<0)){
	printf("-");
	for(int i=l2;i>0;i--)
	a[i]=s2[l2-i]-'0';
	for(int i=l1;i>0;i--)
	b[i]=s1[l1-i]-'0';
	}
	else{
	for(int i=l1;i>0;i--)
	a[i]=s1[l1-i]-'0';
	for(int i=l2;i>0;i--)
	b[i]=s2[l2-i]-'0';
	}
	l=MAX(l1,l2);
	for(int i = 1; i <= l; i ++)
	{
		if(a[i] < b[i])
		{
			a[i + 1] --;
			a[i] += 10;
		}
		ans[i] = a[i] - b[i];
	}
	while (ans[l] == 0) l--;
	if(l==0)
	printf("0");
	for(int i=l;i>0;i--)
	printf("%d",ans[i]);
	}
	return 0;
}
