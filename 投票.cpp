#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
int main()
{
	int n,i,cnt=0,ct=0,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&v);
		if(v==1)
		cnt++;
		else if(v==-1)
		ct++;
		
	}
	if(cnt>ct)
	printf("Question on resolution put and agreed to");
	else if(cnt<ct)
	printf("Question on resolution put but failed to");
	else
	printf("Galactic council will discuss on this");
	return 0;
}