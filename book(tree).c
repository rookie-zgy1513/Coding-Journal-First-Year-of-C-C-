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
#define MAXLENGTH 32
typedef struct node{
    char word[MAXLENGTH];
    int count;
    struct node *lchild;
    struct node *rchild;
}BTNode, *BTNodeptr;
BTNodeptr root = NULL;
char txtword[MAXLENGTH];
int getword(FILE *fp, char word[])
{
    int i = 0;
    int c;
    while (!isalpha(c=(fgetc(fp))))
    {
        if (c==EOF)
            return EOF;
        else
            continue;
    }
    do {
        word[i++] = tolower(c);
    } while (isalpha(c=(fgetc(fp))));
    word[i] = '\0';
    return 1;
}
BTNodeptr insertword(BTNodeptr p, char word[])
{
    if (p==NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        strcpy(p->word, word);
        p->count = 1;
        p->lchild = p->rchild = NULL;
    }
    else if ((strcmp(p->word, word))>0)
        p->lchild = insertword(p->lchild, word);
    else if ((strcmp(p->word, word))<0)
        p->rchild = insertword(p->rchild, word);
    else
        p->count++;
    return p;
}
void in_output(BTNodeptr t){
	if (t!=NULL)
    {
        in_output(t->lchild);
        printf("%s %d\n",t->word,t->count);
        in_output(t->rchild);
    }
}
int main()
{
	FILE*fp;
	fp=fopen("article.txt", "r");
	while(getword(fp,txtword)!=EOF){
		root=insertword(root,txtword);
	}
	int cnt=1;
	BTNodeptr p=root;
	printf("%s ",p->word);
	p=p->rchild;
	while(cnt<=2){
		printf("%s ",p->word);
        if (p->rchild==NULL)
            break;
        else
        {
            p = p->rchild;
            cnt++;
        }
	}
	printf("\n");
    in_output(root);
    fclose(fp);
    return 0;
}