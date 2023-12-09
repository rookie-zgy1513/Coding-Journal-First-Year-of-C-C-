#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int flag;
int i, j, k, l, top, lines, mark,m;
int location[256];
int place[256];
char all[256];
char str[256];
char edit[256];//用all储存所有的括号 用edit模拟出入栈
FILE *fp1;

void deal();
void likestack();

int main() {
	fp1 = fopen("example.c", "r");
	i = -1;
	deal();//应该没问题 
	likestack();//寄 
	fclose(fp1);
	return 0;
}

void deal() { //将所有括号存储在all中 将所有括号位置存储在location中
	k=lines = 0;
	while (fgets(str, 216, fp1) != NULL) {
		lines++;
		l = strlen(str);
		for (i = 0; i < l; i++) {
			if (str[i] == '/' && str[i + 1] == '/') {
				break;
			} else if (str[i] == '/' && str[i + 1] == '*') {
				for (j = i + 2; j < l; j++) {
					if (str[j] == '*' && str[j + 1] == '/') {
						flag = 1;
						break;
					}
				}
				while (flag == 0) {
					memset(str, 0, 216);
					fgets(str, 216, fp1);
					lines++;
					l = strlen(str);
					for (j = 0; j < l; j++) {
						if (str[j] == '*' && str[j + 1] == '/') {
							flag = 1;
							break;
						}
					}
				}
				i = j;
			} else if (str[i] == '"') {
				l = strlen(str);
				for (j = i + 1; j < l; j++) {
					if (str[j] == '"') {
						i = j;
						break;
					}

				}
			} else if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}') {
				all[k] = str[i];
				location[k] = lines;
				k++;
				 //储存这个字符＋它的位置
				
			}
		}
		memset(str, 0, 216);
	}
}

void likestack() {
	top = -1;
	l = strlen(all);
	for (k = 0; k < l; k++) {
		top++;
		edit[top] = all[k];
		place[top] = location[k];
		if (edit[top] == '{') {
			if (edit[top - 1] == '('&&top!=0){
			printf("without maching '(' at line %d\n", place[top - 1]);
				mark = 1;
			}
		} else if (edit[top] == ')') {
			if (edit[top - 1] != '(') {
				printf("without maching ')' at line %d\n", place[top]);
				top--;
				mark=1;
				m=1;//说明不用再处理前面多余的‘（’ 
			} else if (edit[top - 1] == '(') {
				top = top - 2;
			}
			
		} else if (edit[top] == '}') {//{(}的情况？ 
			if (edit[top - 1] != '{') {
				printf("without maching '}' at line %d\n", place[top]);
				top--;
				mark=1;//用来标记要不要全部输出完整字符串 
				m=1;//说明不用再处理前面多余的‘（’ 
			} else if (edit[top - 1] == '{') {
				top = top - 2;
			}
		}
	}
	if(mark==0){
		printf("%s",all);
	}
	else if(mark==1&&top!=-1&&m!=1){
		for(i=0;i<=top;i++){
			if((edit[i]=='('||edit[i]=='{')){
				printf("without maching '%c' at line %d\n",edit[i], place[i]);
			}
		}
	}
		
}

