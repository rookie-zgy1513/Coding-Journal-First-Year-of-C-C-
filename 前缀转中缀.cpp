#include<string>
#include<iostream>
#include<ctype.h>   //要用到isalpha()和isdigit()函数来识别字母与数字字符 
#include<stack>
using namespace std;
void WritrExpr(string& E){
	stack<string> var_or_num;	 //用来存放常量(0-9)或变量(大小写字母) 
	int len = E.size();
	for(int i=len-1;i>=0;i--){ //由于是前缀表达式，故从后往前遍历 
		if(isalpha(E[i])||isdigit(E[i])){      //读到常量或变量则将其保存在栈中 
			string t(1,E[i]);
			var_or_num.push(t);
		}
		if(E[i]=='+'||E[i]=='-'||E[i]=='*'||E[i]=='/'||E[i]=='^'){  //读到运算符则取出栈顶的两个元素 
			string s="(";                   //左括号 
			s += var_or_num.top();  var_or_num.pop(); //第一个运算数，出栈 
			string t(1,E[i]);
			s += t;         //将第一个运算数放到左括号后面 
			s += var_or_num.top();  var_or_num.pop();        //第二个运算数出栈 
			s +=")";           //补上右括号 
			var_or_num.push(s);   //将结果放入栈中 
		}
	}
	cout<<var_or_num.top();     //输出栈顶元素也即最终结果 
}
int main(){
	cout<<"输入前缀表达式"<<endl;
	string E;	getline(cin,E);
	WritrExpr(E);
	return 0;	
}