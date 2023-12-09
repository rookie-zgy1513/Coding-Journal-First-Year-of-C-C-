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
#define MAXWORD  85
int trie_stopwords[1601000][26]={0};
int num_stopwords[1601000]={0};
int pos_stopwords=0;
int trie_articlewords[1000010][26]={0};
int num_articlewords[1000010]={0};
int flag_articlewords[1000010]={0};
int pos_articlewords=0;
int t;
typedef struct Word{
	char word[MAXWORD];
	long long cnt;
}Word;
Word wordlist[160000];
char tempword[1000010][MAXWORD];
void insert_stopwords(char *str)
{
    int p=0;
    for(int i=0; str[i]; i++)
    {
        int n=str[i]-'a';
        if(trie_stopwords[p][n]==0)
            trie_stopwords[p][n]=++pos_stopwords;
        p=trie_stopwords[p][n];
    }
    num_stopwords[p]=1; //在p结尾的单词数量+1 单词唯一
}
int search_stopwords(char *str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=str[i]-'a';
        if(trie_stopwords[p][n]==0) return 0;//不存在
        p=trie_stopwords[p][n];
    }
    return num_stopwords[p]==1;
}
int mytolower(int c)
{
	if(c<=90&&c>=65)
		return c+32;
	else if(c>=97&&c<=122)
		return c;
	return -1;
}
int getword(FILE *fp_article,char *word)
{
	if(feof(fp_article)) return -1;
	int ch=fgetc(fp_article);
	if(ch=='\f')
		return -1;
	ungetc(ch,fp_article);
	int i=0,temp=0,flag=0;
	ch=fgetc(fp_article);
	while(!feof(fp_article))
	{
		temp=mytolower(ch);
		if(temp!=-1)
		{
			flag=1;
			word[i++]=temp;
		}
		else if(ch=='\f')
		{
			if(flag==1)
			{
				ungetc(ch,fp_article);
				word[i]='\0';
				return 1;
			}
			return -1;
		}
		else
		{
			if(flag==1)
			{
				word[i]='\0';
				return 1;
			}
		}
		ch=fgetc(fp_article);
	}
	if(flag==1)
	{
		word[i]='\0';
		return 1;
	}
	return -1;
}


void insert_articlewords(char *str)
{
    int p=0;
    for(int i=0; str[i]; i++)
    {
        int n=str[i]-'a';
        if(trie_articlewords[p][n]==0)
            trie_articlewords[p][n]=++pos_articlewords;
        p=trie_articlewords[p][n];
    }
    num_articlewords[p]++; //在p结尾的单词数量+1 单词唯一
    flag_articlewords[p]=1;
}

int search_articlewords(char *str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=str[i]-'a';
//        if(trie_articlewords[p][n]==0) return 0;//不存在
        p=trie_articlewords[p][n];
    }
    return num_articlewords[p];
}
int find_articlewords(char *str)
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=str[i]-'a';
//        if(trie_articlewords[p][n]==0) return 0;//不存在
        p=trie_articlewords[p][n];
    }
    t=p;
    return flag_articlewords[p];
}
int cmp1(const void*c,const void*d){

	if(((struct Word *)d)->cnt>((struct Word *)c)->cnt) return 1 ;
	else if(((struct Word *)d)->cnt<((struct Word *)c)->cnt) return -1 ;
	else if(strcmp(((struct Word *)c)->word,((struct Word *)d)->word)>0) return 1 ;
	else if(strcmp(((struct Word *)c)->word,((struct Word *)d)->word)<0) return -1 ;
	else return 0;
}
int main(int argc,char *argv[])
{
	int n,m,N,M,q;
	char ch;
	FILE *file_stopwords,*file_article_sample,*fp_result;
	fp_result = fopen("result_z.txt","w");
	file_stopwords = fopen("stopwords.txt", "r");
	file_article_sample = fopen("article.txt", "r");
	char word[MAXWORD];
    while( fscanf(file_stopwords,"%s",word) != EOF) //从文件中读入停用词
        insert_stopwords(word);
        fclose(file_stopwords);
        char sym=fgetc(file_article_sample);
	while(!feof(file_article_sample))
	{
		int i=0,a=0,b;
		ungetc(sym,file_article_sample);
		char name[100];
		fscanf(file_article_sample,"%s",name);
		while(getword(file_article_sample,word)!=-1)
		{
			if (!search_stopwords(word))
            insert_articlewords(word);
            strcpy(tempword[a++],word);
		}
		//当前建立完成
		for(b=0;b<a;b++)
		{
			if (!search_stopwords(tempword[b])){
				if(find_articlewords(tempword[b])==1){
					flag_articlewords[t]++;
					strcpy(wordlist[i].word,tempword[b]);
					wordlist[i++].cnt=search_articlewords(tempword[b]);
				}
			}
            
		}
		q=i;
		qsort(wordlist,q,sizeof(wordlist[0]),cmp1);
		F(i,0,q-1)
		fprintf(fp_result,"%s %lld\n",wordlist[i].word,wordlist[i].cnt);
		F(i,0,4)
		fprintf(fp_result,"\n");
		memset(num_articlewords,0,1000010);
		memset(flag_articlewords,0,1000010);
		memset(wordlist,0,10000);
		memset(trie_articlewords,0,sizeof(trie_articlewords));
		memset(tempword,'\n',sizeof(tempword));
		pos_articlewords=0;
	}
	fclose(fp_result);
	fclose(file_article_sample);
	return 0;
}