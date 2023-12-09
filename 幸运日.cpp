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
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int check_date(int year, int month, int day)
{
        int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
        if ( year < 0 )
        {
                
                return 0;
        }
 
        if ( month < 1 || month > 12 )
        {
                
                return 0;
        }
 
        if ( month == 2 )
        {
                // 判断如果是闰年,则修改二月的monthDays[1]值为29
                if ( (year % 400 == 0) || \
                     (year % 100 != 0 && year % 4 == 0)
                   )
                {
                        monthDays[1] = 29;
                }
        }
 
        if ( day < 1 || day > monthDays[month-1] )
        {
                
                return 0;
        }
 	else
        return 1;
}
int islucky(int date) {
    char r[10];
    sprintf(r, "%d", date);
    return strstr(r, "102") == NULL ? 0 : 1;
}
int main()
{
	int d1,d2;
	long long sum=0;
	while(scanf("%d%d",&d1,&d2)!=EOF){
		sum=0;
		F(i,d1,d2){
			if(!check_date(i/10000,(i%10000)/100,i%100))continue;
			sum=sum+islucky(i);
		}
		printf("%lld\n",sum);
	}
	return 0;
}