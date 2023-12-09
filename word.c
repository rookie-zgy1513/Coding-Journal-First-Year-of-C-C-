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
#define MAXWORD 50
struct node{
    char word[MAXWORD];
    int count;
    struct node* link;
};
char word[MAXWORD];
struct node *Wordlist ;
int get_word(FILE *fp, char *w)
{
    int c;
    while (!isalpha(c=fgetc(fp)))
    {
        if (c==EOF)
        {
            return c;
        }
        else continue;
    }
    do{
        *w++ = tolower(c);
        }while(isalpha(c=fgetc(fp)));//这里用do-while可以保证至少循环一次
    *w='\0';
    return 1;
}
int insert_word(struct node *p, char *w)
{
    struct node *q;
    q = (struct node*)malloc(sizeof(struct node));
    if (q==NULL)
        return -1;
    strcpy(q->word, w);
    q->count = 1;
    q->link = NULL;
    if (Wordlist == NULL)
        Wordlist = q;//链表开头
    else if (p==NULL)
    {
        q->link = Wordlist;
        Wordlist = q;
    }//更换头节点
    else
    {
        q->link = p->link;
        p->link = q;
    }//插入节点
    return 0;
}
int search_word(char *w)
{
    struct node *p = NULL, *q = NULL;
    for (p=Wordlist; p!=NULL; q=p,p=p->link)
    {
        if (strcmp(w, p->word)<0)
        {
            break;
        }
        else if (strcmp(w, p->word)==0)
        {
            p->count++;
            return 0;
        }
    }
    return insert_word(q, w);
}
int main()
{
	FILE*fp;
	fp=fopen("article.txt","r+");
	struct node *p = NULL;
    p = (struct node *)malloc(sizeof(struct node));
	while (get_word(fp, word)!=EOF){
	search_word(word);
	/*for (p=Wordlist; p!=NULL; p=p->link)
    {
        printf("%s %d\n",p->word,p->count);
    }*/
	}  
    for (p=Wordlist; p!=NULL; p=p->link)
    {
        printf("%s %d\n",p->word,p->count);
    }
    fclose(fp);
    return 0;
}