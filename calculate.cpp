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
/* 解法1, 递归处理, 适用于带括号的加减乘除运算   */
/* 递归思路: 遇到左括号, 将括号内的元素递归处理, */
/* 递归结束后, 再继续与外层运算计算              */
double dfs(char **str) {
    char *s = *str;
    int len = strlen(s);
    int i = 0;
    double *stack = (double*)malloc(sizeof(double) * len);
    int top = 0;
    int num = 0;
    double res = 0;
    char sign = '*';
    char ch;
	double ans=1.0;
    while (*s != '\0') {
        ch = *s;
        if (isdigit(ch)) { /* 数字处理 */
            num = num * 10 + (ch - '0');
        }
        if (ch == '(') {  /* 遇到左括号, 递归处理 */
            s++;
            num = dfs(&s);
        }
        /* 处理加减号, 左右括号, 结束符 */
        if ((!isdigit(ch) && ch != ' ') || *(s + 1) == '\0') {
        	if (sign == '+') {
                stack[top++] = num;
            } else if (sign == '-') {
                stack[top++] = -num;
            } else if (sign == '*') {
                stack[top - 1] *= num;
            } else if (sign == '/') {
                stack[top - 1] /= num;
            }
            sign = ch;
            num  = 0;
            if (ch == ')') { /* 遇到右括号, 退出本次处理, 更新字符串起始 */
                *str = s;
                break;
            }
        }
        s++;
    }
    while (top > 0) {
        res += stack[--top];
    }
    free(stack);
    return res;
}

double calculate(char * s){
    return dfs(&s);
}
char str[250];
int main()
{
	gets(str);
	printf("%.2lf",calculate(str));
	return 0;
	
}