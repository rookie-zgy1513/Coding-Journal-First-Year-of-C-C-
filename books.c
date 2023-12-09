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
struct list{
	char name[55];
    char author[25];
    char press[35];
    char date[15];
}book[550];
char s[55];
int cmp(const void *p1, const void *p2)
{
    if (strcmp(((struct list *)p1)->name, ((struct list *)p2)->name)>0)
    {
        return 1;
    }
    else if (strcmp(((struct list *)p1)->name, ((struct list *)p2)->name)<0)
    {
        return -1;
    }
    return 0;
}
int main()
{
	FILE *fp1,*fp2;
    fp1 = fopen("books.txt", "r+");
    fp2 = fopen("ordered.txt", "w");
	int op;
	int n,i=0,j=0,flag=0;
	while (fscanf(fp1, "%s%s%s%s",book[i].name,book[i].author,book[i].press,book[i].date)!=EOF)
    {
        i++;
    }
    n=i-1;
	qsort(book, i, sizeof(struct list), cmp);
    while(scanf("%d",&op)!=0){
    	n=i;
    	if(flag)break;
	switch(op){
		case 0:
			flag++;
			break;
		case 1:
			scanf("%s%s%s%s",book[i].name,book[i].author,book[i].press,book[i].date);
                qsort(book, i, sizeof(struct list), cmp);
                i++;
                break;//录入
		case 2:
		scanf("%s",s);
		qsort(book, i, sizeof(struct list), cmp);
		FD(j,0,n){
			if (strstr(book[j].name, s)!=NULL)
                    {
                        printf("%-50s%-20s%-30s%-10s\n",book[j].name,book[j].author,book[j].press,book[j].date);//左对齐
                    }
		}
		break;//查找并输出
		case 3:
		scanf("%s",s);
		FD(j,0,n){
			if(strstr(book[j].name, s)!=NULL){
				book[j].name[0]='\0';
			}
	}
		qsort(book, i, sizeof(struct list), cmp);
		break;//删除
   }
 }
 qsort(book, i, sizeof(struct list), cmp);
 FD(j,0,n){
 	if(strlen(book[j].name))
 	fprintf(fp2, "%-50s%-20s%-30s%-10s\n",book[j].name,book[j].author,book[j].press,book[j].date);
 }
 fclose(fp1);
 fclose(fp2);
 return 0;      
}
