#include<stdio.h>
#include<string.h>
int main()
{
	char b[110];
	int t,flag=0,i,m=1,a[110]={0},length;
	scanf("%d",&t);
	scanf(" %s",b);
	length=strlen(b);
	while(m<=t){
	flag = 0;//一个标记是否找到字符的变量
	char ch;
	scanf(" %c", &ch);
	
for (i = 0; i < length; i++) {
    if (b[i] == ch) {
        //statement
        flag = 1; 
		a[i]=i+1;//查找到了对应的字符，进行标记
    }
}
if (flag == 0) { //遍历整个字符串都没有标记，说明字符不存在
    printf("I'll add that paragraph... after my next reincarnation");//statement
}
else{
	for(i=0;i<110;i++){
		if(a[i]>0)
		printf("%d ",a[i]);
		a[i]=0;
	}
}
printf("\n");
m++;
}
return 0;	
}