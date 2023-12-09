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
/*int a[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int main()
{
	printf("%d %d %d",*(a[2]+3),*(*(a+2)+3),*(a+2)[3]);
	return 0;
}*/
struct elevator{
    int id;
    int floor;
    struct {
        char name[20];
        char tar;
    }passenger;
};
struct elevator elevators[2] = {{1, 2, {"Red", 'q'}}, {4, 5, {"X_ele", 'e'}}};
struct elevator *p = elevators;
int main(){
	printf("%d\n", (p+1)->id);
printf("%d\n", strlen(p->passenger.name));
printf("%c\n", *((*p).passenger.name+2));
printf("%c\n", (*(p+1)).passenger.tar);
return 0;
}
