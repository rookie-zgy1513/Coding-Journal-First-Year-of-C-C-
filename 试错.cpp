/*#include<stdio.h>
int main()
{
	int t,i=2,x,m=1,a[11]={0},b[11]={0};
	int n,c=1,prime[10001]={0};
	while(i<=10000){
		for(x=2;x<i;x++){
			if(i%x!=0)
			prime[i]=i;
			else{prime[i]=0;
			}break;
		}
		i++;
	}
	prime[2]=2;
	scanf("%d",&n);
	printf("%d",prime[n]);
	return 0;
}*/
/*#include<stdio.h>
#include<string.h>
void twist(char str[]);
void minus(char m[],char n[]);
char a[90];
char b[90];
char c[90];
int l1,l2;
int flag=0;
int num=0;

void twist(char str[]){
	int length=strlen(str);
	int i,j;
	char p;
	for(i=0,j=length-1;i<j;i++,j--){
		p=str[i];
		str[i]=str[j];
		str[j]=p;
	}
}

void minus(char m[],char n[]){
	int j,borrow,t;
	t=strlen(m);
	borrow=0;
	for(j=0;j<t;j++){
		if(m[j]-n[j]-borrow>=0){
			c[j]=m[j]-n[j]+'0'-borrow;
			borrow=0;
		}
		else{
			c[j]=m[j]-n[j]+'0'-borrow+10;
			borrow=1;
		}
	} 
}

int main(){
	scanf("%s",a);
	scanf("%s",b);
	twist(a);
	twist(b);
	l1=strlen(a);
	l2=strlen(b);//比较真实位数多少 
	if(l1>l2){
		minus(a,b);
		flag=1;
		
	}   
	else if(l2>l1){
		minus(b,a);
		flag=-1;
		
	}
	
	else{
		for(int i=l1-1;i>0;i--){
			if(a[i]>b[i]){
				flag=1;
			}
			else if(b[i]>a[i]){
				flag=-1;
			}
		}
	l1=strlen(a);
	l2=strlen(b);
		if(flag==1){
			minus(a,b);
		}
		else if(flag==-1){
			minus(b,a);
		}
	}
	
		if(flag==0){
		printf("%d",0);
		}
		else if(flag==1){
			twist(c);
			printf("%s",c);
			
		}
		else{
			twist(c);
			printf("-");
			printf("%s",c);
		}
		return 0;
	}*/
/*#include <stdio.h>
#include <string.h>
#define maxsize 100
char a[maxsize];
char b[maxsize];
char delta[maxsize];
int a_num,b_num,d_num;

int i,j,k,len;
char c;
int flag=1;//取1表示a大，取-1表示b大

void reverse(char s[]){
    int len = strlen(s);
    for(i=0,j=len-1;i<j;i++,j--){
       c=s[i];
       s[i]=s[j];
       s[j]=c;
    }
}

void deletechar(char s[],char c){
    int length=strlen(s);
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++){
        if(s[i]!=c)
            s[j++]=s[i];
    }
    s[j]='\0';
}

void substract(char a[],char b[]){//注意，这里我严格控制了第一个参数表示的整数大于第二个参数表示的整数
    for(i=0;i<len;i++){
        a_num=a[i]-'0';
        b_num=b[i]-'0';
        if(a_num>=b_num)
            delta[i]='0'+a_num-b_num;
        else{
            delta[i]='0'+10+a_num-b_num;
            if(i!=len-1)
                a[i+1]=a[i+1]-1;
        }
    }
}


int main()
{
    gets(a);
    gets(b);
    deletechar(a,' ');
    deletechar(b,' ');
    reverse(a);
    reverse(b);
    int len_a=strlen(a);
    int len_b=strlen(b);
    if(len_a>len_b){
        for(i=len_b;i<len_a;i++)
            b[i]='0';
    }
    else{
        for(i=len_a;i<len_b;i++)
            a[i]='0';
        if(len_b>len_a)
            flag=-1;
        else{
            for(i=0;i<len_a;i++){
                if(a[i]<b[i]){
                    flag=-1;
                    break;
                }
            }
        }
    }
    len=len_a>len_b?len_a:len_b;
    if(flag==-1)
        substract(b,a);
    else
        substract(a,b);
    reverse(delta);
    if(flag==-1)
        printf("-");
    for(i=0;i<len&&delta[i]=='0';i++);
    if(i==len)
        printf("0\n");
    else{
        for(;i<len;i++)
            printf("%c",delta[i]);
    }
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct books {
 char name[60];
 char author[30];
 char pub[35];
 char date[15];
}book[505], temp;
void replace(int n, struct books book[], struct books temp) {
 for (int i = 0;i < n;i++) {
  for (int j = i + 1;j < n;j++) {
   if (strcmp(book[i].name, book[j].name) > 0) {
    temp = book[i];
    book[i] = book[j];
    book[j] = temp;
   }
  }
 }
}
int main() {
 FILE* fp, * fi;
 fp = fopen("books.text", "r");
 fi = fopen("orderd.text", "w");
 int i = 0, len_book = 0,flag=0;
 while (fscanf(fp, "%s%s%s%s", &book[i].name, &book[i].author, &book[i].pub, &book[i].date) != EOF) {
  i++;
 }
 len_book = i;
 int op=0;
 while (scanf("%d", &op) != 0) {
replace(len_book, book, temp);
  if (flag)
   break;
  char a[100];
  if (op == 1) {
   scanf("%s%s%s%s", &book[i].name, &book[i].author, &book[i].pub, &book[i].date);
   len_book++;//还要排序
  }
  if (op == 2) {
   scanf("%s", a);
   for (int i = 0;i < len_book;i++) {
    if (strstr(book[i].name, a) != NULL) {
     printf("%-50s%-20s%-30s%s\n", book[i].name, book[i].author, book[i].pub, book[i].date);
    }
   }
  }
  if (op == 3) {
   scanf("%s", a);
   for (int i = 0;i < len_book; i++) {
    if (strstr(book[i].name, a) != NULL) {
     book[i].name[0] = '0';
    }
   }
  }
  if (op == 0) {
   flag++;
   break;
  }
 }
 for (i = 0;i < len_book; i++) {
  if (book[i].name[0] != '0') {
   fprintf(fi, " %-50s%-20s%-30s%s\n", book[i].name, book[i].author, book[i].pub, book[i].date);
  }
 }
 fclose(fp);
 fclose(fi);
 return 0;
}*/
/*#include<cstdio>

const int maxn = 120;

struct Node {
    int add;    //空闲块地址
    int length; //空闲块大小
    int flag = 0; //flag为空闲块是否还存在
} N[maxn];

int main() {
    int n;
    int m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &N[i].add, &N[i].length);
    }
    int nowindex = 0;
    while(1) {
        int nextindex = -1;
        scanf("%d", &m);
        int maxlength = 0x3fffffff;
        if(m == -1) {
            break;
        }
        for(int i = 0; i < n; i++) {
            int temp = (nowindex + i) % n;
            if(N[temp].length >= m && N[temp].length < maxlength && N[temp].flag == 0) {
                nextindex = temp;
                maxlength = N[temp].length;
            }
        }
        if(nextindex == -1) {
            continue;
        } else {
            if(N[nextindex].length == m) {
                N[nextindex].flag = 1;
                nowindex = (nextindex + 1) % n;
            } else {
                N[nextindex].length -= m;
                nowindex = nextindex;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        int temp = (nowindex + i) % n;
        if(N[temp].flag == 0) {
            printf("%d %d\n", N[temp].add, N[temp].length);
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info {
	int location;
	int size;
	int flag = 0;
};

int main() {
	info place[60];
	int n, i, j, time;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &place[i].location, &place[i].size);
	}
	int min, num, note, done;
	min=0x3fffffff;
	done = 0;//记录这个数有没有对应的内存
	note = -1;//记录合适的且最小的内存位置
	i = 0;
	while (1) {
		scanf("%d", &num);
		min=0x3fffffff;
		if (num == -1)
			break;
		for (time = 0; time < n; time++, i++) { //最坏的情况是循环n次
			if (i == n) {
				i = i - n; //防止爆掉 保证能循环一整轮
			}
			if (place[i].size == num && place[i].flag == 0) {
				place[i].flag = 1;//已经用过了
				done = 1; //标记这次已经搞好了
				break;//刚刚好 则直接删掉 并跳出循环
			} else if (place[i].size > num && place[i].flag == 0) {
				if (place[i].size < min && place[i].flag == 0) {
					min = place[i].size;
					note = i;
				}
			}
		}//比较一圈
		if (done == 0 && note != -1) {//这个数没被处理掉 但是空间足够
			place[note].size = place[note].size - num;
			i = note;//下一轮从它开始
		}
		done = 0;
		note = -1;//为下一轮做准备
	}
	for (time = 0; time < n; time++, i++) {
		if (i == n) {
			i = i - n;
		} else {
			if (place[i].flag != 1) {
				printf("%d %d\n", place[i].location, place[i].size);
			}
		}
	}
	return 0;
}*/
/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int op[5005],s,a,b,x[5005],tap,tip,quan;
	int ss[5005],sa[5005]={0},sb[5005]={0};
	char temp[30];
	int i=1,j=1,k=1,l,m;
	quan=(1<<26)-1;
	scanf("%d",&op[i]);
	while(op[i]!=-1)
	{
		if(op[i]==0)
		{
			scanf("%d",&s);
			ss[j]=s;
			j++;
		}
		else
		{
			scanf("%d%d%d",&a,&b,&x[k]);
			scanf("%s",temp);
			for(l=0;l<a;l++)
			{
				tap=temp[l]-97;
				sa[k]+=(1<<tap);
			}
			scanf("%s",temp);
			for(l=0;l<b;l++)
			{
				tap=temp[l]-97;
				sb[k]+=(1<<tap);
			}
			k++;
	    } 
	    i++; 
	    scanf("%d",&op[i]);
	}
	j=1;
	k=1;
	l=0;
	for(m=1;m<i;m++)
	{
		printf("Case %d:\n",m);
		if(op[m]==0)
		{
			if(ss[j]==0)
			printf("Empty set\n");
			else
			{
			printf("{");
		while(ss[j]/2!=0)
		{
			if(ss[j]&1==1)
			{
				tap='a'+l;
				printf("%c,",tap);
			}
			l++;
			ss[j]=ss[j]>>1;
		}
		tap='a'+l;
		printf("%c}\n",tap);
		l=0;
	    }
		}
		else
		{
			if(sa[k]==sb[k])
			printf("Set A is equal to set B!\n");
			else{
			
			if((sa[k]>sb[k])&&((sa[k]-sb[k])==(sa[k]^sb[k])))
			printf("Set B is the subset of set A!\n");
			else if((sa[k]<sb[k])&&((sb[k]-sa[k])==(sa[k]^sb[k])))
			printf("Set A is the subset of set B!\n");
			else
			printf("No subset relationship!\n");
			
			if(x[k]==0)
			{
				printf("The intersection of set A and set B is:");
				tip=sa[k]&sb[k];
			}
			else if(x[k]==1)
			{
				printf("The union of set A and set B is:");
				tip=sa[k]|sb[k];
			}
			else if(x[k]==2)
			{
				printf("The complement of set A is:");
				tip=quan-sa[k];
			}
			else if(x[k]==3)
			{
				printf("The difference of set A and set B is:");
				tip=sa[k]-(sa[k]&sb[k]);
			}
			else if(x[k]==4)
			{
				printf("The complement of the intersection of set A and set B is:");
				tip=quan-(sa[k]&sb[k]);
			}
			else
			{
				printf("The complement of the union of set A and set B is:");
				tip=quan-(sa[k]|sb[k]);
			}
				
				if(tip==0)
			printf("Empty set\n");
	        else
			{
				printf("{");
		while(tip/2!=0)
		{
			if(tip&1==1)
			{
				tap='a'+l;
				printf("%c,",tap);
			}
			l++;
			tip=tip>>1;
		}
		tap='a'+l;
		printf("%c}\n",tap);
		l=0;
			}
       }
       k++;
	}
}
	return 0;
}
#include <stdio.h>
#include <stdbool.h>
#define MAX_N 500000
#define MAX_M 500000
int n, m;
int a[MAX_N + 1];
int cnt[MAX_M + 1];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int left = 1, right = 1;
    int len = 0, minLen = MAX_N + 1;
    bool found = false;
    while (right <= n) {
        cnt[a[right]]++;
        if (cnt[a[right]] == 1 && a[right] <= m) {
            len++;
        }
        while (len == m) {
            found = true;
            minLen = (right - left + 1) < minLen ? (right - left + 1) : minLen;
            cnt[a[left]]--;
            if (cnt[a[left]] == 0 && a[left] <= m) {
                len--;
            }
            left++;
        }
        right++;
    }
    if (found) {
        printf("%d\n", minLen);
    } else {
        printf("Not Find\n");
    }
    return 0;
}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int fun(int);
int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		printf("%d",fun(fun(fun(a))));
	}
	return 0;
}
int fun(int x)
{
    int k=0;
	while(x!=0)
	{
		if(x&1==1)
		k++;
		x=x>>1;
	}
	return k;
}
#include<stdio.h>
#include<math.h>
double zgm(double a,int b)
{
	double ans=0;
	while(b)
	{
		ans+=(2/(sqrt(1+(b*b)/(a*a))));
		b--;
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	double min=0,max=100000,mid=50000,t;
	t=zgm(mid,n)-n+0.5;
	while(fabs(max-min)>1e-8) 
	{
		if(t>0)
		max=mid;
		else{
		min=mid;
		}
		mid=(max+min)/2;
		t=zgm(mid,n)-n+0.5;
	}
	printf("%.6lf",max);
	return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(0);
    }

    s->top++;
    s->data[s->top] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        exit(0);
    }

    char c = s->data[s->top];
    s->top--;

    return c;
}

char peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        exit(0);
    }

    return s->data[s->top];
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

char *infix_to_postfix(char *infix) {
    Stack s;
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));
    int i, j;

    init_stack(&s);
    j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        if (!is_operator(infix[i])) {
            postfix[j] = infix[i];
            j++;
        } else {
            while (s.top >= 0 && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j] = pop(&s);
                j++;
            }
            push(&s, infix[i]);
        }
    }

    while (s.top >= 0) {
        postfix[j] = pop(&s);
        j++;
    }

    postfix[j] = '\0';

    return postfix;
}

int main() {
    char infix[100], *postfix;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    postfix = infix_to_postfix(infix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}