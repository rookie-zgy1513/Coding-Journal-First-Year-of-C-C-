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
	int n,op,i,m,l,a,b;
	char ch;
	char str1[1010];
	char str[35];
	scanf("%d",&n);
	scanf("%s",str1);
	for(i=1;i<=n;i++){
		scanf("%d",&op);
		l=strlen(str1);
	
		
			if(op==1){
			scanf("%d",&a);
			for(a=a;a-1<l;a++){
				str1[a-1]=0;
			}
			}
			
			else if(op==2){
			scanf("%s",str);
			for(m=0;m<strlen(str);m++){
				str1[l+m]=str[m];
			}
			l=l+strlen(str);
			}
			
			else if(op==3){
			scanf("%d %c",&b,&ch);
			str1[b-1]=ch;	
			}
		}
	for(i=0;i<l;i++){
		printf("%c",str1[i]);
	}
	return 0;
}