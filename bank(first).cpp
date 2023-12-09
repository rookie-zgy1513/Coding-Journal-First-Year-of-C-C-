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
typedef struct node
{
	int ar,lf,dur;
}person;
person cust[10000];
person comp[10000],temp;
int head=0,tail=-1,m=0;
int t; 
int num[150];
int col=3;
int main()
{
	bool flag=false;
	int i,j,r;
	F(i,1,5)
	{
		comp[i].ar=0;
		comp[i].lf=0;
		comp[i].dur=0;
	}
	scanf("%d",&t);
	F(i,1,t)
	scanf("%d",&num[i]);
	for(i=1;i<=t;i++){
		for(j=1;j<=num[i];j++){
			scanf("%d",&cust[++tail].dur);
			cust[tail].ar=i;
		}
		if((tail-head+1)/col>=7&&col<5)col++;
		if((tail-head+1)/col>=7&&col<5)col++;
		for(j=1;j<=col;j++)
		{
			flag=false;
			if(head==tail+1)break;
			for(r=0;r<=col-1;r++){
				if(comp[5-r].ar==0){
					flag=true;
					break;
				}
				if(comp[5-r].lf+comp[5-r].dur<=i){
					flag=true;
					break;
				}
			}
			if(flag){
			cust[head].lf=i;
			comp[5-r]=cust[head];
			printf("%d : %d\n",head+1,cust[head].lf-cust[head].ar);
			head++;
			}
		}
		if((tail-head+1)/(col)<7&&col>3)col--;
        if((tail-head+1)/(col)<7&&col>3)col--;	
	}
	while(head<=tail)
	{
		for(j=1;j<=col;j++)
		{
			flag=false;
			if(head==tail+1)break;
			for(r=0;r<=col-1;r++){
				if(comp[5-r].ar==0){
					flag=true;
					break;
				}
				if(comp[5-r].lf+comp[5-r].dur<=i){
					flag=true;
					break;
				}
			}
			if(flag){
			cust[head].lf=i;
			comp[5-r]=cust[head];
			printf("%d : %d\n",head+1,cust[head].lf-cust[head].ar);
			head++;
			}
		}
		    if((tail-head+1)/(col)<7&&col>3)col--;
            if((tail-head+1)/(col)<7&&col>3)col--;	       					
		
		i++;
	}
	return 0;
}