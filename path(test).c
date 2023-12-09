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
struct stack{
	int op;
	int num;
};
int top=-1;
struct stack Stack[1000]; 
char s[50];
int main()
{
	int n,m=0,flag=0;
	char ch;
	while(1){
		scanf("%d-%d",&n,&m);
		if(n==0&&m==0)break;
		if(top>=0){
			flag=0;
			if((n==7&&Stack[top].op==8)||(n==8&&Stack[top].op==7)||(n==6&&Stack[top].op==5)||(n==5&&Stack[top].op==6)){
			if(m!=Stack[top].num){
				Stack[top].num=abs(m-Stack[top].num);
				Stack[top].op = ((m-Stack[top].num)>0?(n):(Stack[top].op));
				
			}
			else if(Stack[top].num==m){
				Stack[top].op=0;Stack[top].num=0;
				top--;
				
			}
		}
		else if(Stack[top].op==n){
			Stack[top].num=Stack[top].num+m;
		}
		else {
			Stack[++top].op=n;Stack[top].num=m;
		}
		}
		if(top<0){
		Stack[++top].op=n;Stack[top].num=m;
		}
	}
	for(int i=0;i<top;i++){
		if(Stack[i].op==Stack[i+1].op){
			Stack[i+1].num=Stack[i+1].num+Stack[i].num;
			Stack[i].num=-1;
		}
	}
	if(top<0)
	printf("0-0 ");
	else{
	while(top>=0){
		if(Stack[top].op==5){
			if(Stack[top].num!=-1)
			printf("6-%d ",Stack[top--].num);
			flag++;
		}
		if(Stack[top].op==6){
			if(Stack[top].num!=-1)
			printf("5-%d ",Stack[top--].num);
			flag++;
		}
		if(Stack[top].op==7){
			if(Stack[top].num!=-1)
			printf("8-%d ",Stack[top--].num);
			flag++;
		}
		if(Stack[top].op==8){
			if(Stack[top].num!=-1)
			printf("7-%d ",Stack[top--].num);
			flag++;
		}
		if(Stack[top].op==0&&flag==0){
			if(Stack[top].num!=-1)
			printf("0-0 ");
		}
	}
	}
	
	return 0;
	
	
}