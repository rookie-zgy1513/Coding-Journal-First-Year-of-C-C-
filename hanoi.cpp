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
#define eps 1e-6
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#include <stdio.h>
void hanoi(int n, char from, char via, char to);
void count_move(int i, char from, char to);
int main(int argc, const char * argv[])
{
    int n;
    char a,b,c;
    scanf("%c %c %c",&a,&b,&c);
    scanf("%d",&n);
    hanoi(n, a, b, c);
    return 0;
}

void count_move(int i, char from, char to)
{
    printf("Eika moved Koishi %02d form the %c to the %c\n",i,from,to);
}
void hanoi(int n, char from, char via,char to)
{
    if (n==1)
    {
        count_move(n, from, to);
        return;
    }
    hanoi(n-1, from, to, via);
    count_move(n, from, to);
    hanoi(n-1, via, from, to);
}