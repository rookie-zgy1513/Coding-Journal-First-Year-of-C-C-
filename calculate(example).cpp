#include<stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#define MaxSize 50
typedef double ElemType;
 
typedef struct {	//定义操作数栈
	ElemType data[MaxSize];
	int top;
}NumStack;
 
typedef struct {	//定义运算符栈
	char data[MaxSize];
	int top;
}StrStack;
 
// 将运算符出栈，操作数栈依次出栈两个作为右操作数和左操作数，计算结果并入栈操作数栈
void Calculate(StrStack& StrS, NumStack& NumS) {
	char operate = StrS.data[StrS.top--];
	printf("%c ", operate); //弹出的运算符是后缀表达式，输出显示一下
	ElemType right = NumS.data[NumS.top--];
	ElemType left = NumS.data[NumS.top--];
	ElemType result;
	switch (operate) {
	case '+':result = left + right; break;
	case '-':result = left - right; break;
	case '*':result = left * right; break;
	case '/':result = left / right; break;
	}
	NumS.data[++NumS.top] = result;
}
 
 
// 将字符串表示的中缀表达式转换为后缀表达式输出，同时计算结果
void MiddleToSuffix(char str[]) {
	NumStack NumS;
	StrStack StrS;
	NumS.top = -1;	//初始化操作数栈
	StrS.top = -1;	//初始化运算符栈
	printf("后缀表达式为:");
	for (int i = 0; i < strlen(str); i++) {	//依次扫描字符串
		/* 1. 若为操作数，求后缀表达式则直接输出，计算值则压入操作数栈*/
		char temp[MaxSize];	//用于将字符串数字转换为数值
		int j = 0, flag = 0;	//flag用于判断当前是否是数值
		while (isdigit(str[i]) || str[i] == '.') {
			temp[j++] = str[i++];
			flag = 1;
		}
		if (flag == 1) {
			temp[j] = '\0';
			NumS.data[++NumS.top] = atof(temp);	//操作数直接入操作数栈，同时输出显示
			printf("%g ", NumS.data[NumS.top]);
		}
		/* 2. 若为界限符，左括号则压入运算符栈，右括号则弹出运算符栈的运算符直到遇到左括号并输            　　　　　　　
　　　　　出显示，后缀表达式是不显示括号的；同时每次弹出一个运算符，则依次弹出操作数栈的两个操　　　　　　　　 
          作数分别作为右操作数和左操作数计算结果并压入操作数栈*/
		if (str[i] == '(') {
			StrS.data[++StrS.top] = str[i];
		}
		else if (str[i] == ')') {
			while (StrS.data[StrS.top] != '(') {
				Calculate(StrS, NumS);
			}
			StrS.top--;	//将左括号出栈
		}
		/* 3. 若为运算符，弹出运算符栈中优先级更大和同级的运算符直到栈空或左括号，同时输出弹出 
         的运算符以及计算结果，最后将该运算符入栈*/
		else if (str[i] == '+' || str[i] == '-') {	/*由于加法和减法优先级最低，故运算符栈 
                                                         栈顶只要是运算符都会一直出栈*/
			while (StrS.top != -1 && StrS.data[StrS.top] != '(') {
				Calculate(StrS, NumS);
			}
			StrS.data[++StrS.top] = str[i];
		}
		else if (str[i] == '*' || str[i] == '/') {	/*由于乘法和除法优先级最高，故只能运算 
                                                       符栈顶是乘法或除法才可以持续弹出*/
			while (StrS.top != -1 && StrS.data[StrS.top] != '(' && (StrS.data[StrS.top] == '*' || StrS.data[StrS.top] == '/')) {
				Calculate(StrS, NumS);
			}
			StrS.data[++StrS.top] = str[i];
		}
		else if (str[i] == ' ') {
			// 若为空格则继续扫描
		}
	}
	while(StrS.top != -1){	//若运算符栈不空则一直出栈到空，并计算结果，最终操作数栈中的元素即为最终计算结果
		Calculate(StrS, NumS);
	}
	printf("\n表达式的计算结果为:%g", NumS.data[NumS.top]);
}
 
void Practice() {
	char str[MaxSize];
	gets(str);
	MiddleToSuffix(str);
}
 
int main() {
	Practice();
	return 0;
}