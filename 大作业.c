////////////////
//目前题目思路不是太复杂可以拆分
//先想出如何拆分出一篇篇文章，再对文章进行操作，具体对于sample中每一篇操作类似
//接着就是如何统计词频，可以采用前辈经验，用Trie树实现（还需要学），之后就是再删除stopwords
//之后研究怎么读取hash，之后生成指纹并不难
//最后就是算汉明距离再排序，运用快排
//目前难点集中在如何进行文件操作上，对于三种不同文件要用三种不同的处理方法(article,hash,stopwords)，这需要研究，再就是学习Trie树
//先完成，再完美！！！
/////////////////////
#pragma pack (16)
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
//Trie字典树(停用词)
int trie_stopwords[16010][26]={0};
int num_stopwords[16010]={0};
int pos_stopwords=0;
typedef struct webfinger{
	char webnum[100];
	char webfinger[130];
}webfinger,*pwebfinger;
webfinger Web[100001],Web_new[100001];
int Web_count=0,Web_new_count=0;
int hashvalue[10001][130];
int trie_articlewords[1000010][26]={0};
int num_articlewords[1000010]={0};
int flag_articlewords[1000010]={0};
int pos_articlewords=0;
int t;
/*typedef struct Word{
	char word[MAXWORD];
	long long cnt;
}Word,*Wordptr; 
Word wordlist[10000];*/
long long wordlist[10000];
char result[4][100001][100];
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
/*int cmp1(const void*c,const void*d){

	if(((struct Word *)d)->cnt>((struct Word *)c)->cnt) return 1 ;
	else if(((struct Word *)d)->cnt<((struct Word *)c)->cnt) return -1 ;
	else if(strcmp(((struct Word *)c)->word,((struct Word *)d)->word)>0) return 1 ;
	else if(strcmp(((struct Word *)c)->word,((struct Word *)d)->word)<0) return -1 ;
	else return 0;
}*/
int cmp(const void*c,const void*d){
	return *(long long *)d-*(long long*)c;
}
int main(int argc, char *argv[]){
	int n,m,N,M,q;
	char ch;
	N=atoi(argv[1]);
	M=atoi(argv[2]);
	FILE *file_stopwords,*file_article,*file_sample,*file_hashvalue,*file_result;
	file_stopwords = fopen("stopwords.txt", "r");
	file_article = fopen("article.txt", "r");
	file_sample = fopen("sample.txt", "r");
	file_hashvalue = fopen("hashvalue.txt", "r");
	file_result = fopen("result.txt", "w");
	char word[MAXWORD];
    while( fscanf(file_stopwords,"%s",word) != EOF) //从文件中读入停用词
        insert_stopwords(word);
        fclose(file_stopwords);
//停用词树构建完成
	char line[200];
	for(n=0;n<N;n++)
	{
		fscanf(file_hashvalue,"%s",line);
		for(m=0;m<M;m++)
		{
			hashvalue[n][m]=line[m]-'0';
		}
	}
	fclose(file_hashvalue);
	char sym=fgetc(file_article);
	while(!feof(file_article))
	{
		int i=0,a=0,b;
		ungetc(sym,file_article);
		char name[100];
		fscanf(file_article,"%s",name);
		strcpy(Web[Web_count].webnum,name);
		while(getword(file_article,word)!=-1)
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
					//strcpy(wordlist[i].word,tempword[b]);
					wordlist[i++]=search_articlewords(tempword[b]);
				}
			}
            
		}
		q=i;
		//qsort(wordlist,q,sizeof(wordlist[0]),cmp1);
		qsort(wordlist,q,sizeof(wordlist[0]),cmp);
		for(m=0;m<M;m++)
		{
			int j;
			long long sum=0;
			for(j=0;j<N;j++)
			{
				if(hashvalue[j][m]==1)
				{
					sum=sum+(long long)wordlist[j];
				}
				else
				{
					sum=sum-(long long)wordlist[j];
				}
			}
			if(sum>0)
			{
				Web[Web_count].webfinger[m]='1';
			}
			else
			{
				Web[Web_count].webfinger[m]='0';
			}
		}
		Web_count++;
		memset(num_articlewords,0,1000010);
		memset(flag_articlewords,0,1000010);
		memset(wordlist,0,10000);
		memset(trie_articlewords,0,sizeof(trie_articlewords));
		memset(tempword,'\n',sizeof(tempword));
		pos_articlewords=0;
		if(!feof(file_article))
			sym=fgetc(file_article);
	}
	memset(num_articlewords,0,1000010);
	memset(flag_articlewords,0,1000010);
	memset(wordlist,0,10000);
	memset(trie_articlewords,0,sizeof(trie_articlewords));
	memset(tempword,'\n',sizeof(tempword));
	pos_articlewords=0;
	fclose(file_article);
	sym=fgetc(file_sample);
	while(!feof(file_sample))
	{
		int i=0,a=0,b;
		ungetc(sym,file_sample);
		char name[100];
		fscanf(file_sample,"%s",name);
		strcpy(Web_new[Web_new_count].webnum,name);
		while(getword(file_sample,word)!=-1)
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
					//strcpy(wordlist[i].word,tempword[b]);
					wordlist[i++]=search_articlewords(tempword[b]);
				}
			}
            
		}
		q=i;
		//qsort(wordlist,q,sizeof(wordlist[0]),cmp1);
		qsort(wordlist,q,sizeof(wordlist[0]),cmp);
		for(m=0;m<M;m++)
		{
			int j;
			long long sum=0;
			for(j=0;j<N;j++)
			{
				if(hashvalue[j][m]==1)
				{
					sum=sum+(long long)wordlist[j];
				}
				else
				{
					sum=sum-(long long)wordlist[j];
				}
			}
			if(sum>0)
			{
				Web[Web_new_count].webfinger[m]='1';
			}
			else
			{
				Web[Web_new_count].webfinger[m]='0';
			}
		}
		//printf("%s\n",Web[Web_new_count].webfinger);
		Web_new_count++;
		memset(num_articlewords,0,1000010);
		memset(flag_articlewords,0,1000010);
		memset(wordlist,0,10000);
		memset(trie_articlewords,0,sizeof(trie_articlewords));
		memset(tempword,'\n',sizeof(tempword));
		pos_articlewords=0;
		if(!feof(file_sample))
			sym=fgetc(file_sample);
	}
	fclose(file_sample);
	int k=0,l=0;
	int ham=0,num[4]={0,0,0,0},flag[4]={0,0,0,0},F=0,s;
	for(l=0;l<Web_count;l++)
	{
		ham=0;
		for(s=0;s<M;s++)
		{
			if(Web_new[0].webfinger[s]!=Web[l].webfinger[s])
			{
				ham++;
			}
		}
		if(ham<=3)
		{
			F=1;
			flag[ham]=1;
			strcpy(result[ham][num[ham]++],Web[l].webnum);
		}
	}
	printf("%s\n",Web_new[0].webnum);
	fprintf(file_result,"%s\n",Web_new[0].webnum);
	if(F==1)
	{
		int p=0;
		for(;p<4;p++)
		{
			if(flag[p]==1)
			{
				printf("%d:",p);
				fprintf(file_result,"%d:",p);
				for(s=0;s<num[p];s++)
				{
					printf("%s ",result[p][s]);
					fprintf(file_result,"%s ",result[p][s]);
				}
				printf("\n");
				fprintf(file_result,"\n");
			}
		}
	}
	for(k=1;k<Web_new_count;k++)
	{
		ham=0;F=0;num[0]=0;num[1]=0;num[2]=0;num[3]=0;flag[0]=0;flag[1]=0;flag[2]=0;flag[3]=0;
		for(l=0;l<Web_count;l++)
		{
			ham=0;
			for( s=0;s<M;s++)
			{
				if(Web_new[k].webfinger[s]!=Web[l].webfinger[s])
				{
					ham++;
				}
			}
			if(ham<=3)
			{
				F=1;
				flag[ham]=1;
				strcpy(result[ham][num[ham]++],Web[l].webnum);
			}
		}
		fprintf(file_result,"%s\n",Web_new[k].webnum);
		if(F==1)
		{
			int p=0;
			for(;p<4;p++)
			{
				if(flag[p]==1)
				{
					fprintf(file_result,"%d:",p);
					for(s=0;s<num[p];s++)
					{
						fprintf(file_result,"%s ",result[p][s]);
					}
					fprintf(file_result,"\n");
				}
			}
		}
	}
	fclose(file_result);
	return 0;	
}
