#pragma GCC optimize ("O3")
#pragma once
#pragma pack (16)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXWORD  85
typedef struct tnode{
	char isword;
	char isleaf;
	char word[100];
	int frequency;
	struct tnode *ptr[26];
}tnode,*tnodeptr;

typedef struct webfinger{
	char webnum[100];
	char webfinger[130];
	tnodeptr root;
}webfinger,*webfingerptr;
webfinger Web[100001],Web_new[100001];
int Web_count=0,Web_new_count=0;
tnodeptr Nwords;
tnodeptr stopwords_tire;
tnodeptr weight[100001],allweight[100001],stopweight[100001];					//储存weight,这样树不用再遍历一遍
int weight_count,allweight_count,stopweight_count;
char hashvalue[10001][130];
char result[4][100001][100];

int mytolower(int c);
int getword(FILE *fp_article,char *word);			//按网页获取单词
tnodeptr createtree();
tnodeptr wordTrie0(tnodeptr root,char *w);
tnodeptr wordTrie1(tnodeptr root,char *w);
tnodeptr wordTriest(tnodeptr root,char *w);
int cmp(const void*,const void*);

int main(int argc,char *argv[])
{
	Nwords=createtree();
	int a,b,N=0,M=0;
	int lN=strlen(argv[1]),lM=strlen(argv[2]);
	for(a=0;a<lN;a++)
	{
		N=N*10+argv[1][a]-'0';
	}
	for(b=0;b<lM;b++)
	{
		M=M*10+argv[2][b]-'0';
	}
	char word[MAXWORD];
//建立停用词树
	FILE *fp_stopwords=fopen("stopwords.txt","r");
	tnodeptr stopwords_tire=createtree();
	while( getword(fp_stopwords,word)!=-1)
	{
		stopwords_tire=wordTriest(stopwords_tire,word);
	}
	fclose(fp_stopwords); 
//建完
//先将N行，M列hash值提取
	FILE *fp_hashvalue=fopen("hashvalue.txt","r");
	char line[200];
	int n,m;
	for(n=0;n<N;n++)
	{
		fscanf(fp_hashvalue,"%s",line);
		strcpy(hashvalue[n],line);
		strcpy(hashvalue[n]+M,"\0");
	}
	fclose(fp_hashvalue);
	//hashvalue存储
	FILE *fp_article=fopen("article.txt","r");
	char sym=fgetc(fp_article);
	while(!feof(fp_article))
	{
		ungetc(sym,fp_article);
		char name[100];
		fscanf(fp_article,"%s",name);
		strcpy(Web[Web_count].webnum,name);
	//对当前网页和全体网页建立相应特征字典树
		tnodeptr root=createtree();
		weight_count=0;
		while(getword(fp_article,word)!=-1)
		{
			char *mem=word;							//检查word是否为stopword 
			tnodeptr q=stopwords_tire;
			for(;*mem!='\0';mem++)
			{
				if(q->ptr[*mem-'a']==NULL)
				{
					break;
				}
				q=q->ptr[*mem-'a'];
			}
			if(!(*mem=='\0'&&q->isword==1))
			{
				root=wordTrie1(root,word);
				Nwords=wordTrie0(Nwords,word);			//全体网页字典树建立中
			}
		}
		Web[Web_count].root=root;
		//当前建立完成
		Web_count++;
		if(!feof(fp_article))
			sym=fgetc(fp_article);
	}
	fclose(fp_article);
	//已有网页字典树集合建立完成，全体建立完成
	qsort(allweight,allweight_count,sizeof(allweight[0]),cmp);
	for(n=0;n<Web_count;n++)
	{
		int frequencyarray[10001];
		tnodeptr *mem=allweight;
		for(m=0;m<N;m++)
		{
			int i=0;
			tnodeptr q=Web[n].root;
			for(;mem[m]->word[i]!='\0';i++)
			{
				if(q->ptr[mem[m]->word[i]-'a']==NULL)
				{
					break;
				}
				q=q->ptr[mem[m]->word[i]-'a'];
			}
			if(mem[m]->word[i]!='\0')
			{
				frequencyarray[m]=0;
			}
			else
			{
				frequencyarray[m]=q->frequency;
			}
		}
		//已获取N个特征向量权重
		for(m=0;m<M;m++)
		{
			int j;
			long long sum=0;
			for(j=0;j<N;j++)
			{
				if(hashvalue[j][m]=='1')
				{
					sum=sum+(long long)frequencyarray[j];
				}
				else
				{
					sum=sum-(long long)frequencyarray[j];
				}
			}
			if(sum>0)
			{
				Web[n].webfinger[m]='1';
			}
			else
			{
				Web[n].webfinger[m]='0';
			}
		}
		//Web[n]指纹建立完毕，只是字符数组，非字符串
	}
	FILE *fp_sample=fopen("sample.txt","r");
	sym=fgetc(fp_sample);
	while(!feof(fp_sample))
	{
		ungetc(sym,fp_sample);
		char name[100];
		fscanf(fp_sample,"%s",name);
		strcpy(Web_new[Web_new_count].webnum,name);
	//对当前网页建立相应特征字典树
		tnodeptr root=createtree();
		weight_count=0;
		while(getword(fp_sample,word)!=-1)
		{
			char *mem=word;							//检查word是否为stopword
			tnodeptr q=stopwords_tire;
			for(;*mem!='\0';mem++)
			{
				if(q->ptr[*mem-'a']==NULL)
				{
					break;
				}
				q=q->ptr[*mem-'a'];
			}
			if(!(*mem=='\0'&&q->isword==1))
				root=wordTrie1(root,word);
		}
		Web_new[Web_new_count].root=root;
		//当前网页字典树建立完成
		int frequencyarray[10001];
		tnodeptr *mem=allweight;
		for(m=0;m<N;m++)
		{
			int i=0;
			tnodeptr q=Web_new[Web_new_count].root;
			for(;mem[m]->word[i]!='\0';i++)
			{
				if(q->ptr[mem[m]->word[i]-'a']==NULL)
				{
					break;
				}
				q=q->ptr[mem[m]->word[i]-'a'];
			}
			if(mem[m]->word[i]!='\0')
			{
				frequencyarray[m]=0;
			}
			else
			{
				frequencyarray[m]=q->frequency;
			}
		}
		for(m=0;m<M;m++)
		{
			int j;
			long long sum=0;
			for(j=0;j<N;j++)
			{
				if(hashvalue[j][m]=='1')
				{
					sum=sum+frequencyarray[j];
				}
				else
				{
					sum=sum-frequencyarray[j];
				}
			}
			if(sum>0)
			{
				Web_new[Web_new_count].webfinger[m]='1';
			}
			else
			{
				Web_new[Web_new_count].webfinger[m]='0';
			}
		}
		Web_new_count++;
		if(!feof(fp_sample))
			sym=fgetc(fp_sample);
	}
	fclose(fp_sample);
	FILE *fp_result=fopen("result.txt","w");
	int k,l;
	int ham=0,num[4]={0,0,0,0},flag[4]={0,0,0,0},F=0;
	for(l=0;l<Web_count;l++)
	{
		ham=0;
		for(m=0;m<M;m++)
		{
			if(Web_new[0].webfinger[m]!=Web[l].webfinger[m])
			{
				ham++;
			}
			if(ham>3)break;
		}
		if(ham<=3)
		{
			F=1;
			flag[ham]=1;
			strcpy(result[ham][num[ham]++],Web[l].webnum);
		}
	}
	printf("%s\n",Web_new[0].webnum);
	fprintf(fp_result,"%s\n",Web_new[0].webnum);
	if(F==1)
	{
		int p=0;
		for(;p<4;p++)
		{
			if(flag[p]==1)
			{
				printf("%d:",p);
				fprintf(fp_result,"%d:",p);
				int s;
				for(s=0;s<num[p];s++)
				{
					printf("%s ",result[p][s]);
					fprintf(fp_result,"%s ",result[p][s]);
				}
				printf("\n");
				fprintf(fp_result,"\n");
			}
		}
	}
	for(k=1;k<Web_new_count;k++)
	{
		ham=0;F=0;num[0]=0;num[1]=0;num[2]=0;num[3]=0;flag[0]=0;flag[1]=0;flag[2]=0;flag[3]=0;
		for(l=0;l<Web_count;l++)
		{
			ham=0;
			for(m=0;m<M;m++)
			{
				if(Web_new[k].webfinger[m]!=Web[l].webfinger[m])
				{
					ham++;
				}
				if(ham>3)break;
			}
			if(ham<=3)
			{
				F=1;
				flag[ham]=1;
				strcpy(result[ham][num[ham]++],Web[l].webnum);
			}
		}
		fprintf(fp_result,"%s\n",Web_new[k].webnum);
		if(F==1)
		{
			int p=0;
			for(;p<4;p++)
			{
				if(flag[p]==1)
				{
					fprintf(fp_result,"%d:",p);
					int s;
					for(s=0;s<num[p];s++)
					{
						fprintf(fp_result,"%s ",result[p][s]);
					}
					fprintf(fp_result,"\n");
				}
			}
		}
	}
	fclose(fp_result);
	return 0;	
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
tnodeptr createtree()
{
	int i;
	tnodeptr p=(tnodeptr)malloc(sizeof(tnode));
	p->isword=0;p->isleaf=1;p->frequency=0;p->word[0]='\0';
	for(i=0;i<26;i++)
	{
		p->ptr[i]=NULL;
	}
	return p;
}
tnodeptr wordTrie0(tnodeptr root,char *w)
{
	tnodeptr p=root;
	char *ini=w;
	for(;*w!='\0';w++)
	{
		if(p->ptr[*w-'a']==NULL)
		{
			p->ptr[*w-'a']=createtree();
			p->isleaf=0;
		}
		p=p->ptr[*w-'a'];
	}
	if(p->isword==0)
	{
		strcpy(p->word,ini);
		p->isword=1;
		p->frequency++;
		allweight[allweight_count++]=p;
	}
	else
	{
		p->frequency++;
	}
	return root;
}
tnodeptr wordTrie1(tnodeptr root,char *w)
{
	tnodeptr p=root;
	char *ini=w;
	for(;*w!='\0';w++)
	{
		if(p->ptr[*w-'a']==NULL)
		{
			p->ptr[*w-'a']=createtree();
			p->isleaf=0;
		}
		p=p->ptr[*w-'a'];
	}
	if(p->isword==0)
	{
		strcpy(p->word,ini);
		p->isword=1;
		p->frequency++;
		weight[weight_count++]=p;
	}
	else
	{
		p->frequency++;
	}
	return root;
}
tnodeptr wordTriest(tnodeptr root,char *w)
{
	tnodeptr p=root;
	char *ini=w;
	for(;*w!='\0';w++)
	{
		if(p->ptr[*w-'a']==NULL)
		{
			p->ptr[*w-'a']=createtree();
			p->isleaf=0;
		}
		p=p->ptr[*w-'a'];
	}
	if(p->isword==0)
	{
		strcpy(p->word,ini);
		p->isword=1;
		p->frequency++;
		stopweight[stopweight_count++]=p;
	}
	else
	{
		p->frequency++;
	}
	return root;
}
int cmp(const void *c,const void *d)
{
	tnodeptr *e1=(tnodeptr*)c,*e2=(tnodeptr*)d;
	if((*e1)->frequency>(*e2)->frequency)
	{
		return -1;
	}
	else if((*e1)->frequency<(*e2)->frequency)
	{
		return 1;
	}
	else if(strcmp((*e1)->word,(*e2)->word)>0)			//字典序小的在前
	{
		return 1;
	}
	else if(strcmp((*e1)->word,(*e2)->word)<0)
	{
		return -1;
 	}
	else return 0; 
}

