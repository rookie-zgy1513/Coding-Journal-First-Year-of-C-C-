#include <stdio.h>
#define size 10

void MergeSort(int *num, int len)
{
    int i, j, k;
    // 临时数组，用于归并子序列
    int sort[size];
    // 左区间的起点、终点下标
    int L_start = 0, L_end = 0;
    // 右区间的起点、终点下标
    int R_start = 0, R_end = 0;

    // 区间长度 i，两倍递增
    for (i = 1; i < len; i *= 2)
    {
        // 根据区间长度划分多个左右两个区间
        for (L_start = 0; L_start < len - i; L_start = R_end + 1)
        {
            // 确定左右两个区间各自的起点、终点下标
            L_end = L_start + i - 1;
            R_start = L_end + 1;
            R_end = R_start + i - 1;
            
            // 右区间可能会超出数组长度
            if (R_end >= len)
            {
                R_end = len - 1;
            }

            // 临时数组下标
            j = 0;
            // 按大小顺序收集左右两个区间子序列的数据到临时数组中
            while (L_start <= L_end && R_start <= R_end)
            {
                // 比较左右区间内数据的大小
                if (num[L_start] < num[R_start])
                {
                    sort[j++] = num[L_start++];
                }
                else
                {
                    sort[j++] = num[R_start++];
                }
            }

            // 收集两个区间子序列中可能剩余的数据
            while (L_start <= L_end)
            {
                sort[j++] = num[L_start++];
            }
            while (R_start <= R_end)
            {
                sort[j++] = num[R_start++];
            }

            // 最后将排序好的数据重新录入原数组中
            while (j > 0)
            {
                num[--R_start] = sort[--j];
            }
        }
    } 
}

int main()
{
    int i, num[size] = {5, 3, 7, 1, 9, 2, 0, 4, 8, 6};
    MergeSort(num, size);
    
    for ( i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}//考试的时候记得看和改size
