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
int main()
{
	char x,y;
	int n,year[3],month[3],day[3],date[3],d,cnt=0;
	scanf("%d",&n);
	F(i,1,n)
	{
		cnt=0;
		scanf("%d%c%d%c%d",&year[1],&x,&month[1],&y,&day[1]);
		date[1]=year[1]*10000+month[1]*100+day[1];
		scanf("%d%c%d%c%d",&year[2],&x,&month[2],&y,&day[2]);
		date[2]=year[2]*10000+month[2]*100+day[2];
		if(date[1]==date[2])
		printf("Today\n");
		else 
		{
			for(;date[1]<date[2];date[1]++){
				if(check_date(date[1]/10000,(date[1]%10000)/100,date[1]%100))
				cnt++;
			}
			if(cnt==1)
			printf("Yesterday\n");
			else if(year[2]-year[1]!=0){
			printf("%d-%02d-%02d %d days ago\n",year[1],month[1],day[1],cnt);
			}
			else
			printf("%02d-%02d %d days ago\n",month[1],day[1],cnt);
			
		}
	}
	return 0;
}