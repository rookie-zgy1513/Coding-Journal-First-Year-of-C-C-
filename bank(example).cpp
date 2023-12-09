#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#define max(a,b) ( ((a)>(b)) ? (a):(b) )
#define min(a,b) ( ((a)>(b)) ? (b):(a) )
typedef struct node
{
	int ar,lf;
}pp;
pp a[10000];
int head=0,tail=-1;
int t; 
int main()
{
	int num;
	int i,j;
	int col=3;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&num);
		for(j=1;j<=num;j++)
		{
			a[++tail].ar=i;
		}
		if((tail-head+1)/col>=7&&col<5)col++;
		if((tail-head+1)/col>=7&&col<5)col++;
		for(j=1;j<=col;j++)
		{
			if(head==tail+1)break;
			a[head].lf=i;
			printf("%d : %d\n",head+1,a[head].lf-a[head].ar);
			head++;					
		}
        if((tail-head+1)/(col)<7&&col>3)col--;
        if((tail-head+1)/(col)<7&&col>3)col--;	    
	}
	while(head<=tail)
	{
		for(j=1;j<=col;j++)
		{
			if(head==tail+1)break;
			a[head].lf=i;
			printf("%d : %d\n",head+1,a[head].lf-a[head].ar);
			head++; }
		    if((tail-head+1)/(col)<7&&col>3)col--;
            if((tail-head+1)/(col)<7&&col>3)col--;	       					
		
		i++;
	}
	return 0;
}
