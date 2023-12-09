#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define N 100
struct student/*定义结构体类型*/
{
    int number;
	char name[30];
	char department[30];
	char major[30];
};
struct student b[N];
int findNumber;
char findName[30],printfDepartment[30],printfMajor[30],department[30];
int menu(void);
int dataInput(struct student*pStudent);
void searchNumber(struct student*pStudent,int n,int findNumber);
void searchName(struct student*pStudent,int n,char*pFindName);
void printfDataDepartment(struct student*pStudent,int n,char*pPrintfDepartment);
void printfDataMajor(struct student*pStudent,int n,char*pPrintfMajor);
void departmentCount(struct student*pStudent,int n,char*pDepartment);




int menu(void)/*显示菜单*/
{
	char flag='A';
	int item=-1;
	printf("\n");
	printf("\t\t————————————————————————\n");
	printf("\t\t                                                \n");
	printf("\t\t              学籍信息管理系统菜单              \n");
	printf("\t\t                                                \n");
	printf("\t\t            F.查找学生信息\n");
	printf("\t\t            B.按照学院/专业分类显示学生信息\n");
	printf("\t\t            D.统计：按照所在学院统计学生人数\n");
	printf("\t\t            Q.退出\n");
    printf("\t\t                                                \n");
	printf("\t\t————————————————————————\n");

	while(flag=='A')
	{
	printf("请输入选项（F/B/D/Q）:");
	scanf(" %c",&flag);

	    if(flag=='F'||flag=='B'||flag=='D'||flag=='Q')
		{
	         
	         if(flag=='F')
			 {
			     printf("按学生学号查询请按1；按学生姓名查询请按2：\n");
				 scanf("%d",&item);
				 if(item==1||item==2)
				     ;
                 else
				 {
					 flag='F';
					 printf("数据错误请重新输入\n");
				 }
			 }
			 if(flag=='B')
			 {
			     printf("按学院浏览请按1;按专业浏览请按2:\n");
				 scanf("%d",&item);
                 if(item==1||item==2)
				 item+=2;
				 else
				 {
					 flag='B';
					 printf("数据错误请重新输入\n");
				 }
			 }
			 if(flag=='D')
			 item=5;
			 if(flag=='Q')
			 item=6;
		}
	    else
		{
		    flag='A';
		    printf("\n输入错误。");
		}
		
	}
	return item;
}

int dataInput(struct student*pStudent)   /*信息录入*/
{
	int i,n;
    printf("请输入想要输入信息的学生数量：");
	scanf("%d",&n);
	printf("请按如下顺序录入数据：\n");
	printf("%-15s%-15s%-15s%-15s\n","学号","姓名","学院","专业");
	for(i=0;i<n;i++)
	{
	    printf("请输入第%d位学生的信息:\n",i+1);
		scanf("%d%s%s%s",&pStudent[i].number,pStudent[i].name,pStudent[i].department,pStudent[i].major);
	}
	return n;
}


void searchNumber(struct student*pStudent,int n,int findNumber)/*按学号查询*/
{
	int i,flag=0;
    for(i=0;i<n;i++)
	{
        if(pStudent[i].number==findNumber)
		{
		    if (flag==0)
			{
		  	    printf("\n%-15s%-15s%-15s%-15s\n","学号","姓名","学院","专业");
                flag=1;
			}
            printf("%-15d%-15s%-15s%-15s\n",pStudent[i].number,pStudent[i].name,pStudent[i].department,pStudent[i].major);
		}
	}
    if(flag==0) 
    printf("\n查无此人!\n");
}


void searchName(struct student*pStudent,int n,char*pFindName)/*按姓名查询*/
{
	int i,flag=0;
    for(i=0;i<n;i++)
	{
		if(strcmp(pStudent[i].name,pFindName)==0)
		{
	    	if (flag==0)
			{
			    printf("\n%-15s%-15s%-15s%-15s\n","学号","姓名","学院","专业");
                flag=1;
			}
            printf("%-15d%-15s%-15s%-15s\n",pStudent[i].number,pStudent[i].name,pStudent[i].department,pStudent[i].major);
		}
	}
    if(flag==0) 
    printf("\n查无此人!\n");
}


void printfDataDepartment(struct student*pStudent,int n,char*pPrintfDepartment)/*按学院浏览*/
{
    int i=0;
    for(i=0;i<n;i++)
	{
        if(strcmp(pStudent[i].department,pPrintfDepartment)==0)
	    printf("\n%-15d%-15s%-15s%-15s\n",pStudent[i].number,pStudent[i].name,pStudent[i].department,pStudent[i].major);
	}
}


void printfDataMajor(struct student*pStudent,int n,char*pPrintfMajor)/*按专业浏览*/
{
    int i=0;
    for(i=0;i<n;i++)
	{
        if(strcmp(pStudent[i].major,pPrintfMajor)==0)
	    printf("\n%-15d%-15s%-15s%-15s\n",pStudent[i].number,pStudent[i].name,pStudent[i].department,pStudent[i].major);
	}
}


void departmentCount(struct student*pStudent,int n,char*pDepartment)/*按所在学院统计学生数量*/
{
    int i,count=0;
    for(i=0;i<n;i++)
	{
        if(strcmp(pStudent[i].department,pDepartment)==0)
        count++;
        
	}
	printf("\n%s共有%d位学生。\n",pDepartment,count);
}


int main(void)
{
    int item,n;
	
	
	n=dataInput(b);
	while(1)
	{
	    item=menu();
		switch(item)
		{
		    case(1):
                 printf("\n请输入学号：");
				 scanf("%d",&findNumber);
				 searchNumber(b,n,findNumber);
				 break;
 		    case(2):
                 printf("\n请输入姓名：");
				 scanf("%s",findName);
				 searchName(b,n,findName);
				 break;
		    case(3):
				printf("\n请输入学院名");
				scanf("%s",printfDepartment);
				printfDataDepartment(b,n,printfDepartment);
				break;
		    case(4):
                printf("\n请输入专业名");
				scanf("%s",printfMajor);
				printfDataMajor(b,n,printfMajor);
				break;
		    case(5):
				printf("\n请输入学院名");
				scanf("%s",department);
				departmentCount(b,n,department);
				break;
			case(6):
				printf("\n谢谢您的使用，再见！\n");
				exit(0);
		}
	}
	return(0);
}