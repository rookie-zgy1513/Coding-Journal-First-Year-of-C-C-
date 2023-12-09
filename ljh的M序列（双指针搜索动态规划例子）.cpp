#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <stdbool.h>
#define ArrayLen(x) (sizeof(x)/sizeof(x[0]))
#define ArraySize(x) (sizeof(x)/sizeof(x[0]))
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define FD(i,l,r) for(int i=(l);i<(r);i++)
#define SWAP(a,b) x^=y,y^=x,x^=y
#define eps 1e-8
#define MIN(a,b) (((a)-(b)<0)?(a):(b))
#define MAX(a,b) (((a)-(b)>0)?(a):(b))
#define read(x) {x=0;char z;while((z=getchar())<48);do x=x*10+(z^48);while((z=getchar())>47);}//快读
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