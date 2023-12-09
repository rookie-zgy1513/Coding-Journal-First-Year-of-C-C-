#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i, l, r) for(int i=(l);i<=(r);i++)
#define FD(i, l, r) for(int i=(l);i<(r);i++)
#define SWAP(a, b) x^=y,y^=x,x^=y
#define eps 1e-8
#define MIN(a, b) (((a)-(b)<0)?(a):(b))
#define MAX(a, b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
int arr[19];
int n;
void dfs(int m,int index,int a) {
    if(m == 0) {
    	if(arr[0] <= n/2){
    		for(int i = 0; i < index;i++) {
        	printf("%d",arr[i]);
        	if(i != index - 1)
        	printf("+");
		}
		printf("\n");
		}
        
        return;
    }
    for (int j = a; j <= m; ++j) {
    	arr[index] = j;
        dfs(m-j,index + 1,j);
    }
}
int main() {
    scanf("%d", &n);
    dfs(n,0,1);
    return 0;
}