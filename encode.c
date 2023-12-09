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
#define ASCII 95
struct node{
    char ch;
    struct node *next;
};
typedef struct node Node;
typedef struct node *Nodeptr;
Nodeptr list=NULL;//用来写自己写的函数里的操作
Nodeptr p0;//用来写主函数里的遍历
char s[35];
char keyword[ASCII+1];
char code[ASCII];
int hash[ASCII] = {0};
int delete_d(char s[])
{
    int i = 0, j = 0;
    for (i=0; i<strlen(s); i++)
    {
        if (!hash[s[i]-' '])
        {
            hash[s[i]-' ']++;
            keyword[j++] = s[i];
        }
        else continue;
    }
    return j;
}
void create_key(char s[],int x)
{
    int j = x;
    char i;
    for (i=32; i<=126; i++)
    {
        if (!hash[i-' '])
        {
            keyword[j++] = i;
        }
        else continue;
    }
}
Nodeptr create_circlelist(Nodeptr list, char s[])
{
    int i = 0;
    Nodeptr q;
    Nodeptr p;
    p = (Nodeptr)malloc(sizeof(Node));
    for (i=0; i<strlen(s); i++)
    {
        q = (Nodeptr)malloc(sizeof(Node));
        q->ch = s[i];
        q->next = NULL;
        if (list==NULL)
        {
            list = q;
			p = q;
        }
        else
        {
            p->next = q;
            p = q;
        }
    }
    p->next = list;
    list = p;
    return list;
}
void create_code(Nodeptr list)
{
    char record;
    char first;
    int i;
    Nodeptr p,q;
    p = (Nodeptr)malloc(sizeof(Node));
    q = (Nodeptr)malloc(sizeof(Node));
    q = list;
    p = q->next;
    record = p->ch;
	first = p->ch;
    while (p->next!=p)
    {
        q->next = p->next;
        free(p);
        p = q->next;
        for (i=0; i<record-1; i++)
        {
            q = p;//别忘了这个
            p = p->next;
        }
        //printf("%d\n",record-' ');
        code[record-' '] = p->ch;
        record = p->ch;
    }
    code[p->ch-' '] = first;
}
int main()
{
	FILE *fp1,*fp2;
	fp1 = fopen("in.txt", "r");
    fp2 = fopen("in_crpyt.txt", "w");
	gets(s);
	int l=delete_d(s);
	char password,ch;
	create_key(keyword, l);
	list=create_circlelist(list, keyword);
	create_code(list);
	while ((ch = fgetc(fp1))!=EOF)
    {
        if (ch>=32 && ch<=126)
        {
            password = code[ch-' '];
            fputc(password, fp2);
        }
        else fputc(ch, fp2);
    }
	fclose(fp1);
    fclose(fp2);
    return 0;
}