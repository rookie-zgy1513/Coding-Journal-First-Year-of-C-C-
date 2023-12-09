#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//最大结点数
#define MAX_POINT 256

//结点数组，方便回收所有结点
struct TREE* treePoint[MAX_POINT];
int treePointP = 0;

//序列数组：前序，中序，后序
char before[MAX_POINT];
char middle[MAX_POINT];
char last[MAX_POINT];

//树的结点
struct TREE {
	struct TREE* left;
	struct TREE* right;
	char ch;
}*root;

/*
find:int
作用：寻找字符串中指定字符的下标
参数说明：
str	字符串
strNum 字符串大小
ch	所要搜寻的字符
*/
int find(char* str, int strNum, char ch);
/*
getBefore:void
作用：前序遍历
参数说明：
root	树的根节点
*/
void getBefore(struct TREE* root);
/*
createLeftTree:void
作用：创建结点的左子树
参数说明：
root	当前树的根节点
left	用于创建左子树的序列的最左下标
right	用于创建左子树的序列的最右下标
注意:区间为闭合区间，即[left,right]
*/
void createLeftTree(struct TREE* root, int left, int right);
/*
createRightTree:void
作用：创建结点的右子树
参数说明：
root	当前树的根节点
left	用于创建右子树的序列的最左下标
right	用于创建右子树的序列的最右下标
注意:区间为闭合区间，即[left,right]
*/
void createRightTree(struct TREE* root, int left, int right);
/*
delTree:void
作用：回收所有结点内存
*/
void delTree();

int find(char* str, int strNum, char ch) {
	for (int i = 0; i < strNum; ++i)
		if (str[i] == ch)
			return i;
	return -1;
}
void getBefore(struct TREE* root) {
	printf("%c", root->ch);
	if (root->left)
		getBefore(root->left);
	if (root->right)
		getBefore(root->right);
}
void createLeftTree(struct TREE* root, int left, int right) {
	if (left > right)
		return;
	if (left == right) {
		root->left = (struct TREE*)malloc(sizeof(struct TREE));
		treePoint[treePointP++] = root->left;
		root->left->left = NULL;
		root->left->right = NULL;
		root->left->ch = middle[left];
		return;
	}
	for (int i = find(last,strlen(last),root->ch)-1; i >= 0; --i) {
		for (int j = left; j <= right; ++j) {
			if (middle[j] == last[i]) {
				root->left = (struct TREE*)malloc(sizeof(struct TREE));
				treePoint[treePointP++] = root->left;
				root->left->left = NULL;
				root->left->right = NULL;
				root->left->ch = middle[j];
				createLeftTree(root->left, left, j - 1);
				createRightTree(root->left, j + 1, right);
				return;
			}
		}
	}
}
void createRightTree(struct TREE* root, int left, int right) {
	if (left > right)
		return;
	if (left == right) {
		root->right = (struct TREE*)malloc(sizeof(struct TREE));
		treePoint[treePointP++] = root->right;
		root->right->left = NULL;
		root->right->right = NULL;
		root->right->ch = middle[right];
		return;
	}
	for (int i = find(last, strlen(last), root->ch) - 1; i >= 0; --i) {
		for (int j = left; j <= right; ++j) {
			if (middle[j] == last[i]) {
				root->right = (struct TREE*)malloc(sizeof(struct TREE));
				treePoint[treePointP++] = root->right;
				root->right->left = NULL;
				root->right->right = NULL;
				root->right->ch = middle[j];
				createLeftTree(root->right, left, j - 1);
				createRightTree(root->right, j + 1, right);
				return;
			}
		}
	}
}
void delTree() {
	for (int i = 0; i < treePointP; ++i)
		free(treePoint[i]);
}
int main()
{
	printf("请输入中序序列:");
	scanf("%s", middle);
	printf("请输入后序序列:");
	scanf("%s", last);
	root = (struct TREE*)malloc(sizeof(struct TREE));
	treePoint[treePointP++] = root;
	root->left = NULL;
	root->right = NULL;
	root->ch = last[strlen(last) - 1];
	createLeftTree(root, 0, find(middle, strlen(middle), root->ch) - 1);
	createRightTree(root, find(middle, strlen(middle), root->ch) + 1, strlen(last) - 1);
	printf("它的先序序列是:");
	getBefore(root);
	delTree();
	return 0;
}
