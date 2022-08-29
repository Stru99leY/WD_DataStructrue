#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Find_Num(int A[], int n)
{
    int i, *B;                          //标记数组
    B = (int *)malloc(sizeof(int) * n); //分配空间
    memset(B, 0, sizeof(int) * n);      //赋初值为0
    for (i = 0; i < n; i++)
    {
        if (A[i] > 0 && A[i] <= n)
        {
            B[A[i] - 1] = 1; //标记数组B,注意数组下标与位数关系
        }
    }
        for (i = 0; i < n; i++)
        {
            if (B[i] == 0)
                break;
        }
        return i + 1; // i从0开始
}
int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3};
    int a1[] = {-5, 3, 2, 3};
    printf("%d", Find_Num(a, 3));
    return 0;
}
