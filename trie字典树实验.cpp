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
int trie[1000010][26],num[1000010]={0},flag[1000010]={0};
int pos;
void InsertTrie(char *str){
	int p=0;
	for(int i = 0;str[i];i++){
		int n=str[i]-'a';
		if(trie[p][n]==0)
			trie[p][n]=++pos;
		p=trie[p][n];	
	}
	num[p]++;
}
int FindTrie(char *str){
	int p=0;
	for(int i=0;str[i];i++){
		int n=str[i]-'a';
		if(trie[p][n]==0)
			return 0;
		p=trie[p][n];
	}
	return num[p];
}
char word[105];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	F(i,1,n){
		scanf("%s",word);
		InsertTrie(word);
	}
	F(i,1,m){
		scanf("%s",word);
		printf("%d\n",FindTrie(word));
	}
	return 0;
}
