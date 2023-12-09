#include<stdio.h>
int main()
{
	int a;
while (scanf("%d", &a) != EOF)
{
	if(a==1){
		printf("本地对了就是对了，交上去WA说明评测机有问题。\n");
	}
	else if(a==2){
	printf("调试调试。\n");	
	}
		else if(a==3){
			printf("没啥问题。在OJ上输入和输出是分开的，不用担心。\n");
		
	}
		else if(a==4){
		printf("SIGESGV大约是数组越界了,SIGFPE大约是除以零了。\n");
	}
		else if(a==5){
		printf("大约是数组越界了。\n");
	}
		else if(a==6){
	    printf("百度一下报错信息。\n");	
	}
		else if(a==7){
	    printf("可能是死循环了，如果显示process exited with return value 3221225477等非零数，可以百度百度这个数字的携带的错误信息。\n");	
	}
		else if(a==8){
		printf("对对对。\n");
	}
   else{
   	printf("你的代码有问题，但是我不知道是什么问题。\n");
   }
   
}
    return 0;
}