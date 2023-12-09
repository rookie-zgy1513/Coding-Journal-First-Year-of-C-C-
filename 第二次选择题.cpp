/*#include<stdio.h>
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
int main()
{
	int x[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, *p1,*p2,*p3;
  p1 = x + 3; 
 p2 = x + 2; 
 p3 = x + 2;
 printf("%d %d %d",*p1++,*(p2++),*++p3);
 return 0;

}
#include<stdio.h>

struct stu{

	int num;

	float TotalScore;

};

void f(struct stu p)

{

	struct stu s[2]={{20044,550},{20045,537}};

	p.num=s[1].num;

	p.TotalScore=s[1].TotalScore;

}

int main()

{

	struct stu s[2]={{20041,703},{20042,580}};

	f(s[0]);

	printf("%d %3.0f\n",s[0].num,s[0].TotalScore);

	return 0;

}*/
/*#include<stdio.h>
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
struct st{

    int x;

    int *y;

} *pt;

int a[ ]={1,2}, b[ ]={3,4};
struct st c[2]={10,a,20,b};

int main()
{
pt=c;
	printf("%d\n%d\n%d\n%d",*pt->y,pt->x,++pt->x,(pt++)->x);
	return 0;
	
}
#include<stdio.h>
void sub(int x,int y,int *z)
{
       *z=y-x;
}
main()
{
          int a,b,c;
          sub(10,5,&a);
          sub(7,a,&b);
          sub(a,b,&c);
          printf("%d,%d,%d\n",a,b,c);
}
#include <stdio.h>
void swap(int *p, int *q)
{
         int *t;
         t=p;
         p=q;
         q=t;
}
main()  
{
          int a=10,b=20;
       
          swap(&a,&b);
           printf("a=%d,b=%d\n",a,b);
} 
#include <stdio.h>
main()  
{
      int a[4] = {1,2,3,4};
      int *p;
      p=&a[2];
      printf("%d ",++*p);
      printf("%d\n",*--p);
} 

struct st{

    int x;

    int *y;

} ;

int a[ ]={1,2}, b[ ]={3,4};

struct st c[2]={10,a,20,b},*pt=c;
int main()
{

	printf("%d\n%d\n%d\n%d",*pt->y,pt->x,++pt->x,(pt++)->x);
	return 0;
}*/
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
/*struct {
    int x;
    char *y;
} tab[2] = {{1, "ab"}, {2, "cd"}}, *p = tab;
int main()
{
	printf("%c", *(++p)->y ); 
	return 0;
	
	
	
	
}*/
/*struct dent
{
 int n;
 int *m;
};
int a=1, b=2, c=3;
struct dent s[3]={{101,&a},{102,&b},{103,&c}};
struct dent *p =s;
int main()
{
	printf("%d",(*p).m);
	//printf("%d\n%d\n%d\n%d",,,,*(++p)->m);
	return 0;
}*/
/*struct st{

    int x;

    int *y;

} *pt;

int a[ ]={1,2}, b[ ]={3,4};
struct st c[2]={10,a,20,b};

int main()
{
pt=c;
printf("%d",(pt++)->x);
	//printf("%d\n%d\n%d\n%d",,,,);
	return 0;
}*/
/*struct student
{
    int age;
    int num;
};
struct student stu[3] = {{1001, 20}, {1002, 19}, {1003, 21}};
struct student *p;

int main()
{
p = stu;
	printf("%d",   (*++p).age);
	return 0;
}*/
void swap(int *p, int *q)
{
         int *t;
         t=p;
         p=q;
         q=t;
}
main()  
{
          int a=10,b=20;
       
          swap(&a,&b);
           printf("a=%d,b=%d\n",a,b);
} 