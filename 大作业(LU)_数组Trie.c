#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define singleN 18000
typedef struct node{
	char word[80];
	int num;
}node;

typedef struct web{
	char name[20];
	char finger[130];
}web;

int single_tire[singleN][26],single_count,single_num[singleN];
web Web[16000],Web_new[1000];						//数据范围 
int Web_count,Web_new_count;
int all_count,all_tire[10000000][26];
node all_num[10000000];
int stop_count,stop_tire[1000][26],stop_num[1000];
char hashvalue[10001][130],result[4][16000][20];;

int mytolower(int c);
int getword(FILE *fp_article,char *word);
//void insert_stop(char *word);
//void insert_all(char *word);
//int find_stop(char *word);
int cmp(const void *E1,const void *E2);

int main(int argc,char *argv[])
{
	int a,N=0,M=0;
	for(a=0;argv[1][a]!='\0';a++)
	{
		N=N*10+argv[1][a]-'0';
	}
	for(a=0;argv[2][a]!='\0';a++)
	{
		M=M*10+argv[2][a]-'0';
	}
	char word[80];
//建立停用词树
	FILE *fp_stopwords=fopen("stopwords.txt","r");
	while(getword(fp_stopwords,word)!=-1)
	{
		//insert_stop(word);
	int i,p=0;
	for(i=0;word[i]!='\0';i++)
	{
		int n=word[i]-'a';
		if(stop_tire[p][n]==0)
			stop_tire[p][n]=++stop_count;
		p=stop_tire[p][n];
	}
	stop_num[p]++;
	}
//	fclose(fp_stopwords); 
//停用词树建立完成
//先将前N行、M列hash值提出来，以便后续不再I/O文件hashvalue
	FILE *fp_hashvalue=fopen("hashvalue.txt","r");
	char line[130];
	int n,m;
	for(n=0;n<N;n++)
	{
		fscanf(fp_hashvalue,"%s",line);
		for(m=0;m<M;m++)
		{
			hashvalue[n][m]=line[m];
		}
	}
//	fclose(fp_hashvalue);
//hashvalue已存储到hashvalue[][]中
//打开已获取网页全体,通过字典树确定前N个单词 
	FILE *fp_article=fopen("article.txt","r");
	while(!feof(fp_article))
	{
	//对全体网页建立特征字典树 
		while(getword(fp_article,word)!=-1)
		{
			int i,p=0,k=0;
			for(i=0;word[i]!='\0';i++)
			{
				int n=word[i]-'a';
				if(stop_tire[p][n]==0)
					break;
				p=stop_tire[p][n];
			}
			if(word[i]=='\0') k=stop_num[p];
			if(k==0)
		{
			//insert_all(word);
			p=0;
		for(i=0;word[i]!='\0';i++)
		{
			int n=word[i]-'a';
			if(all_tire[p][n]==0)
			all_tire[p][n]=++all_count;
			p=all_tire[p][n];
		}
			all_num[p].num++;
			strcpy(all_num[p].word,word);
			}
		}
	}
	fseek(fp_article,0,SEEK_SET);
	//全体网页字典树建立完成
//获取前N个单词,由此建立网页指纹 
	qsort(all_num,all_count,sizeof(node),cmp);
	while(!feof(fp_article))
	{
		char name[20];
		fscanf(fp_article,"%s",name);
		strcpy(Web[Web_count].name,name);
		memset(single_tire,0,26*singleN);memset(single_num,0,singleN);single_count=0;
//		int single_tire[singleN][26]={0},single_count=0,single_num[singleN]={0};
	//对每个网页建立特征字典树
		while(getword(fp_article,word)!=-1)
		{
	int i,p=0,k=0;
	for(i=0;word[i]!='\0';i++)
	{
		int n=word[i]-'a';
		if(stop_tire[p][n]==0)
			break;
		p=stop_tire[p][n];
	}
	if(word[i]=='\0') k=stop_num[p];
			if(k==0)
			{
				int i,p=0;
				for(i=0;word[i]!='\0';i++)
				{
					int n=word[i]-'a';
					if(single_tire[p][n]==0)
					single_tire[p][n]=++single_count;
					p=single_tire[p][n];
				}
				single_num[p]++;
			}
		}
		//开始获取当前网页指纹 
		int b,frequency[10001];
		for(a=0;a<N;a++)
		{
			int i,p=0;
			for(i=0;all_num[a].word[i]!='\0';i++)
			{
				int n=all_num[a].word[i]-'a';
				if(single_tire[p][n]==0)
					break;
				p=single_tire[p][n];
			}
			if(all_num[a].word[i]=='\0')
			{
				frequency[a]=single_num[p];
			}
			else frequency[a]=0;
		}
		for(b=0;b<M;b++)
		{
			long long sum=0;
			for(a=0;a<N;a++)
			{
				if(hashvalue[a][b]=='1')
					sum=sum+frequency[a];
				else sum=sum-frequency[a];
			}
			if(sum>0)	Web[Web_count].finger[b]='1';
			else	Web[Web_count].finger[b]='0';
		}
		Web_count++;
	}
//	fclose(fp_article);
	//此时已获得了已有网页的指纹
//获取新网页指纹
	FILE *fp_sample=fopen("sample.txt","r");
	char sym=fgetc(fp_sample);
	while(!feof(fp_sample))
	{
		ungetc(sym,fp_sample);
		char name[20];
		fscanf(fp_sample,"%s",name);
		strcpy(Web_new[Web_new_count].name,name);
		memset(single_tire,0,26*singleN);memset(single_num,0,singleN);single_count=0;
//		int single_tire[singleN][26]={0},single_count=0,single_num[singleN]={0};
	//对每个网页建立特征字典树 
		while(getword(fp_sample,word)!=-1)
		{
	int i,p=0,k=0;
	for(i=0;word[i]!='\0';i++)
	{
		int n=word[i]-'a';
		if(stop_tire[p][n]==0)
			break;
		p=stop_tire[p][n];
	}
	if(word[i]=='\0') k=stop_num[p];
			if(k==0)
			{
				int i,p=0;
				for(i=0;word[i]!='\0';i++)
				{
					int n=word[i]-'a';
					if(single_tire[p][n]==0)
					single_tire[p][n]=++single_count;
					p=single_tire[p][n];
				}
				single_num[p]++;
			}
		}
		//开始获取当前网页指纹 
		int b,frequency[10000];
		for(a=0;a<N;a++)
		{
			int i,p=0;
			for(i=0;all_num[a].word[i]!='\0';i++)
			{
				int n=all_num[a].word[i]-'a';
				if(single_tire[p][n]==0)
					break;
				p=single_tire[p][n];
			}
			if(all_num[a].word[i]=='\0')
			{
				frequency[a]=single_num[p];
			}
			else frequency[a]=0;
		}
		for(b=0;b<M;b++)
		{
			long long sum=0;
			for(a=0;a<N;a++)
			{
				if(hashvalue[a][b]=='1')
					sum=sum+frequency[a];
				else sum=sum-frequency[a];
			}
			if(sum>0)	Web_new[Web_new_count].finger[b]='1';
			else	Web_new[Web_new_count].finger[b]='0';
		}
		Web_new_count++;
		if(!feof(fp_sample))
			sym=fgetc(fp_sample);
	}
//	fclose(fp_sample);
	//此时已获得了新网页的指纹
//比较Hamming distance并输出
	FILE *fp_result=fopen("result.txt","w");
	int k,l,b;
	int ham=0,num[4]={0,0,0,0},flag[4]={0,0,0,0},F=0;
	for(l=0;l<Web_count;l++)
	{
		ham=0;
		for(b=0;b<M;b++)
		{
			if(Web_new[0].finger[b]!=Web[l].finger[b])
			{
				ham++;
			}
		}
		if(ham<=3)
		{
			F=1;
			flag[ham]=1;
			strcpy(result[ham][num[ham]++],Web[l].name);
		}
	}
	printf("%s\n",Web_new[0].name);
	fprintf(fp_result,"%s\n",Web_new[0].name);
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
			for(b=0;b<M;b++)
			{
				if(Web_new[k].finger[b]!=Web[l].finger[b])
				{
					ham++;
				}
			}
			if(ham<=3)
			{
				F=1;
				flag[ham]=1;
				strcpy(result[ham][num[ham]++],Web[l].name);
			}
		}
		fprintf(fp_result,"%s\n",Web_new[k].name);
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
//	fclose(fp_result);
	return 0;
}

int cmp(const void *E1,const void *E2)
{
	node *e1=(node*)E1,*e2=(node*)E2;
	if(e1->num>e2->num) return -1;
	else if(e1->num<e2->num) return 1;
	else if(strcmp(e1->word,e2->word)>0) return 1;
	else if(strcmp(e1->word,e2->word)<0) return -1;
	else return 0;
}

/*void insert_all(char *word)
{
	int i,p=0;
	for(i=0;word[i]!='\0';i++)
	{
		int n=word[i]-'a';
		if(all_tire[p][n]==0)
			all_tire[p][n]=++all_count;
		p=all_tire[p][n];
	}
	all_num[p].num++;
	strcpy(all_num[p].word,word);
}*/

/*void insert_stop(char *word)
{
	int i,p=0;
	for(i=0;word[i]!='\0';i++)
	{
		int n=word[i]-'a';
		if(stop_tire[p][n]==0)
			stop_tire[p][n]=++stop_count;
		p=stop_tire[p][n];
	}
	stop_num[p]++;
}*/

/*int find_stop(char *word)
{
	int i,p=0;
	for(i=0;word[i]!='\0';i++)
	{
		int n=word[i]-'a';
		if(stop_tire[p][n]==0)
			return 0;
		p=stop_tire[p][n];
	}
	return stop_num[p];
}*/

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

