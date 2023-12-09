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
struct users{
	char name[25];
	char number[15];
	char repeat[3];
	int flag;
}list[110];
int i = 0, j = 0;
int n;
int cmp(const void *p1, const void *p2)
{
    struct users *a = (struct users *)p1;
    struct users *b = (struct users *)p2;
    if (strcmp(a->name, b->name)<=0)
        return -1;
    if (strcmp(a->name, b->name)>0)
        return 1;
    return 0;
}
int search_r(int i)
{
    F(j,i+1,n-1)
    {
        if (!strcmp(list[i].name, list[j].name))
            return 1;
    }
    return 0;
}//查重
void delete_r(int i)
{
    F(j,i+1,n-1)
    {
        if (!strcmp(list[j].name, list[i].name)&&(strcmp(list[j].number, list[i].number)!=0))
        {
            list[j].repeat[1]++;
        }//标记
        else if (!strcmp(list[j].name, list[i].name)&&!strcmp(list[j].number, list[i].number))
        {
            list[j].name[0]='@';
        }//去重
    }
}//去重+标记
int main()
{
	
	scanf("%d",&n);
	F(i,0,n-1){
		scanf("%s%s",list[i].name,list[i].number);
        list[i].repeat[0] = '_';
        list[i].repeat[1] = '0';
        list[i].flag=0;
        list[i].repeat[2] = '\0';
	}
	qsort(list, n, sizeof(struct users), cmp);
	F(i,0,n-1){
        if (search_r(i))
        {
            delete_r(i);
        }
    }//去重+标记
    F(i,0,n-1){
        if (list[i].name[0]!='@')
        {
            printf("%s",list[i].name);
            if (list[i].repeat[1]!='0')
            {
                printf("%s",list[i].repeat);
            }
            printf(" %s\n",list[i].number);
        }
    }//格式化输出
    return 0;
}