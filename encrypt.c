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
char key[60];
char code[26];
int record[26];//哈希表记录
int main()
{
	FILE *fp1,*fp2;
    fp1 = fopen("encrypt.txt", "r+");
    fp2 = fopen("output.txt", "w");
	scanf("%s",key);
	int i=0,j=0;
	char c='z';
	FD(i,0,strlen(key)){
		if (!record[key[i]-'a'])
        {
            code[j]=key[i];
            record[key[i]-'a']=1;
            j++;
        }
	}
	while(c>='a'){
		if (!record[(c-'a')])
        {
            code[j]=c;
            j++;
        }
        c--;
	}
	while((c=fgetc(fp1))!=EOF){
		if (isalpha(c))
        {
            fputc(code[c-'a'], fp2);
        }
        else fputc(c, fp2);
	}
	fclose(fp1);
    fclose(fp2);
    return 0;
}