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
char s1[100], s2[100];
int main()
{
    
    int i, j,l;
	scanf("%s", s1);
    l = strlen(s1);
    for (i = 0, j = 0; i < l; i++)
    {
        if (s1[i] == '-')
        {
            if (i > 0 && i < l - 1 && s1[i - 1] < s1[i + 1] &&
                ((s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i + 1] >= 'a' && s1[i + 1] <= 'z') ||
                 (s1[i - 1] >= 'A' && s1[i - 1] <= 'Z' && s1[i + 1] >= 'A' && s1[i + 1] <= 'Z') ||
                 (s1[i - 1] >= '0' && s1[i - 1] <= '9' && s1[i + 1] >= '0' && s1[i + 1] <= '9')))
            {
                for (char c = s1[i - 1] + 1; c < s1[i + 1]; c++)
                {
                    s2[j++] = c;
                }
            }
            else
            {
                s2[j++] = s1[i];
            }
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
   printf("%s\n",s2);
    return 0;
}