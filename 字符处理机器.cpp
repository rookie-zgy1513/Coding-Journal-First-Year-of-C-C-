#include<stdio.h>
int main()
{
	char c;
    int a;
    int i=1,n=1,num=1;
    scanf("%d",&a);
    while(i<=a){
        scanf(" %c",&c);
        
        if('a' <= c && c <= 'z')
          {c = c - 'a' + 'A';
          while(n<=num)
          {printf("%c",c);
          n++;}
          num=1,n=1;
          printf("\n");}
        else if('A' <= c && c <= 'Z')
          {c = c - 'A' + 'a';
          while(n<=num)
          {printf("%c",c);
          n++;}
          num=1,n=1;
          printf("\n");}
		else  if('0' <= c && c <= '9')
        {
            num = c - '0';
            }
        else
         {printf("? *&\\! _//\\a@\\\\\\r\\n! //\\\\\"_\"/\\\\^! ~zZ\n");}
        i++;}
        return 0;
}