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
#define NHASH 3001
#define LENGTH 3500
#define MAXWORD 20
#define MULT 37
#define ALPHABET 26
typedef struct word{
    char word[MAXWORD];
}word;
word dictionary[LENGTH];
int count = 0;
typedef struct idx{
    int position;
    int length;
}idx;
idx letter[ALPHABET];
typedef struct node{
    char word[MAXWORD];
    struct node *next;
}Node,*Nodeptr;
Nodeptr Hash[LENGTH];
int length = 0;
void create_index(idx index[], word list[])
{
	char ch = 'a';
    int i = 0;
    int j = 0;
    for (i=0; i<length-1; i++)
    {
        if (ch==list[i].word[0])
        {
            index[j].length++;
        }
        else
        {
            ch++;
            j++;
            if (index[j-1].length!=0)
            index[j].position = i;
            else
                index[j].position = i-1;
        }
    }
}
unsigned int hash(char *str)
{
    unsigned int h = 0;
    char *p;
    for(p=str; *p!='\0'; p++)
        h = MULT*h + *p;
    return h%NHASH;
}
Nodeptr insert_node(Nodeptr head, char elem[])
{
    Nodeptr p, q, r;
    q = NULL;
    r = (Nodeptr)malloc(sizeof(Node));
    strcpy(r->word, elem);
    r->next = NULL;
    for (p=head; p!=NULL&&strcmp(p->word,elem)<0;q=p,p=p->next);
    if (p==head)
    {
        r->next = head;
        head = r;
        return head;
    }
    else
    {
        q->next = r;
        r->next = p;
    }
    return head;
}
void create_hash(word list[])
{
    int i;
    for (i=0; i<NHASH; i++)
        Hash[i] = NULL;
    for (i=0; i<length-1; i++)
    {
        int t = hash(list[i].word);
        Hash[t] = insert_node(Hash[t], list[i].word);
    }
    return ;
}

void hash_search(Nodeptr head, char key[])
{
    Nodeptr p;
    if (head==NULL)
    {
        printf("0 0\n");
        return;
    }
    count = 1;
    for (p=head; p->next!=NULL&&strcmp(p->word, key)<0; p=p->next)
        count++;
    if (strcmp(p->word, key)==0)
        printf("1 %d\n", count);
    else
        printf("0 %d\n", count);
}
int se_search(word list[], char key[])
{
    int i = 0;
    count = 0;
    for (i=0; i<length; i++)
    {
        if (strcmp(key,list[i].word)==0)
        {
            printf("1 %d\n",count+1);
            return 1;
        }
        if (strcmp(key,list[i].word)<0)
            break;
        count++;
    }
    printf("0 %d\n",count+1);
    return 0;
}
int binary_search(word list[], char key[], int low, int high)
{
    int mid = 0;
    count = 0;
    while (low<=high)
    {
        mid = (low+high)/2;
        count++;
        if (strcmp(list[mid].word, key)==0)
        {
            printf("1 %d\n",count);
            return 1;
        }
        else if (strcmp(key, list[mid].word)<0)
            high = mid-1;
        else if (strcmp(key, list[mid].word)>0)
            low = mid+1;
    }
    printf("0 %d\n",count);
    return 0;
}
int main()
{
	FILE *fp;
    fp = fopen("dictionary3000.txt", "r");
	int i = 0;
    int h;
    char readin[MAXWORD];
    int op;
    char ch;
    while (!feof(fp))
    {
        fscanf(fp, "%s", dictionary[length].word);
        length++;
    }
	create_index(letter, dictionary);
	create_hash(dictionary);
	while (scanf("%s %d",readin,&op)!=EOF)
    {
        switch (op)
        {
            case 1:
                se_search(dictionary, readin);
                break;
            case 2:
                binary_search(dictionary, readin, 0, length-1);
                break;
            case 3:
                for (ch='a'; ch!=readin[0]; ch++);
                if (letter[ch-'a'].length==0)
                    printf("0 0\n");
                else
                {
                    binary_search(dictionary, readin, letter[ch-'a'].position,letter[ch-'a'].position+ letter[ch-'a'].length);
                }
                break;
            case 4:
                h = hash(readin);
                hash_search(Hash[h], readin);
                break;
        }
    }
    fclose(fp);
    return 0;	
}