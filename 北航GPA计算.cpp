/*此程序用于北航GPA计算
百分制学科输入“成绩【空格】学分【回车】”
五级制学科，与百分制学科输入类似，“优秀”“良好”“中等”“及格”“不及格”分别对应成绩“101”“102”“103”“104”“105”
输入“-1”代表输入完毕，按回车即可得到GPA*/
 
//此程序测试时与实际GPA基本一致，但有少许误差，请以实际GPA为准
 
//如果有哪位同志知道误差产生原因可以在下面评论呦~~ (～￣▽￣)～ 
 
#include<stdio.h>
 
int main()
{
	int grade[100]={};//用于储存单科成绩
	double point[100]={};//用于储存单科学分 
	double gpa[100]={};//用于储存单科gpa
	int i;
	double GPA;
	double mark;
	double sum1=0;//学分绩点和 
	double sum2=0;//学分和 
	double sum3=0;
	for(i=0;i<100;i++)
	{
		scanf("%d",&grade[i]);
		if(grade[i]==-1)
		{
			break;
		}
		scanf("%lf",&point[i]);
		sum3=sum3+grade[i]*point[i];
	}
	int n=i;
	for(i=0;i<n;i++)
	{
		if(grade[i]==101)
		{
			gpa[i]=4;
		}
		else if(grade[i]==102)
		{
			gpa[i]=3.5;
		}
		else if(grade[i]==103)
		{
			gpa[i]=2.8;
		}
		else if(grade[i]==104)
		{
			gpa[i]=1.7;
		}
		else if(grade[i]==105)
		{
			gpa[i]=0;
		}
		else
		{
			gpa[i]=4.0-((100.0-grade[i])*(100.0-grade[i])*3.0)/1600.0;
		}
		sum1=sum1+gpa[i]*point[i];
		sum2=sum2+point[i];
	}
	GPA=sum1/sum2;
	mark=sum3/sum2;
	printf("GPA:%lf\n",GPA);
	printf("Point:%lf\n",mark);
	return 0;
} 