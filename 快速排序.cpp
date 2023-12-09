#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s[10000], n, i,k;

int cmp(const void *a, const void *b)
{
     return (*(int *)a - *(int *)b);//由小到大排序
     //return *(int *)b - *(int *)a; 由大到小排序
}

int main()
{
     scanf("%d", &n);
     for(i = 0; i < n; i++) 
         scanf("%d", &s[i]);

     qsort(s, n, sizeof(s[0]), cmp);

     for(i = 0; i < k; i++) 
         printf("%d ", s[i]);

     return 0;
}