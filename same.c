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
struct phone{
	char s[15];
	char sta;
	char in[10];
	char out[10];
};
struct find{
	char s[15];
	char sta;
};
struct find F[1000];
struct phone info[1000];
char search[11];
int cmp(const void *p1, const void * p2){
    struct find *a = (struct find*)p1;
    struct find *b = (struct find*)p2;
    if(strcmp(a->s,b->s)!=0)
        return strcmp(b->s,a->s);
    else
        return a->sta-b->sta;
}
int main()
{
	int n,i,j,r,flag=0,first,last,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %s %c%s%s",info[i].s,&info[i].sta,info[i].in,info[i].out);
	}
	scanf("%s",search);
	F(i,0,n-1){
		if(strcmp(search,info[i].s)==0&&flag==0){
			first=i;
			flag=1;
		}
		if(strcmp(search,info[i].s)!=0&&flag==1){
			last=i-1;
			flag=0;
			break;
		}
	}
	F(i,first,last){
		int a=atoi(info[i].in);
		int b=atoi(info[i].out);
		F(j,0,first-1){
			int A=atoi(info[j].in);
			int B=atoi(info[j].out);
			if((b>=A&&b<B)||(a>A&&a<=B)){
				if(info[i].sta==info[j].sta){
					strcpy(F[cnt].s,info[j].s);
					F[cnt++].sta=info[j].sta; 
					//printf("%d\n",j);
					//printf("%s %c\n",F[cnt-1].s ,F[cnt-1].sta);
				}
			}
		}
		F(j,last+1,n-1){
			int A=atoi(info[j].in);
			int B=atoi(info[j].out);
			if((b>=A&&b<B)||(a>A&&a<=B)){
				if(info[i].sta==info[j].sta){
					strcpy(F[cnt].s,info[j].s);
					F[cnt++].sta=info[j].sta; 
					//printf("%d\n",j);
					//printf("%s %c\n",F[cnt-1].s ,F[cnt-1].sta);
				}
			}
		}
	}
	if(cnt>0){
	qsort(F,cnt,sizeof(struct find),cmp);
	F(i,0,cnt-1){
		printf("%s %c\n",F[i].s,F[i].sta);
	}
}
	//printf("%d",cnt);
	return 0;
	
}