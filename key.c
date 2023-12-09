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
char key1[60],key2[60];
char code[26];
int record[26];
void string_rev(char s[])
{
    int hi = 0, low = 0;//定义hi和low的目的就是方便循环交换数据
    char temp;//只是一个工具人而已
    while (s[hi]!='\0')
    {
        hi++;//hi的值代表了字符串的长度，以后做相关类型的题的时候也可以定义这么一个变量记录
    }
    for (hi--; hi>low; low++,hi--)//头尾交换，以hi>low作为循环结束的条件，防止循环回去等于没交换，例如一个字符串有五个字符则每次交换（1，5）（2，4），3不交换。
    {
        temp=s[low];
        s[low]=s[hi];
        s[hi]=temp;
    }
}
void delete_s(char s[]){
	int l=strlen(s);
	int j=0;
	F(i,0,l-1){
		if(isalpha(s[i])){
			s[i]=tolower(s[i]);
			if(!record[s[i]-'a']){
				key2[j]=s[i];
            record[s[i]-'a']=1;
            j++;
			}
		}
	}
	key2[j]='\0';
}
int main()
{
	int i=0,j;
	char c='z';
	char m='a';
	gets(key1);
	delete_s(key1);
	string_rev(key2);
	int l=strlen(key2);
	for(i=0;i<=l-1;i++){
		code[i]=key2[i];
	}
	j=i;
	while(c>='a'){
		if (!record[(c-'a')])
        {
            code[j]=c;
            j++;
        }
        c--;
	}
	while(m<='z'){
		printf("%c %c\n",m,code[m-'a']);
		m++;
	}
	//printf("%s\n%s\n%s\n",key1,key2,code);
	return 0;
	
}