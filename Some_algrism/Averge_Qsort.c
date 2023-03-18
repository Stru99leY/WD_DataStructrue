/* 利用平均数作为轴值 改进快排 */
#include <stdio.h>

// 求中枢节点
int Partion(int a[], int low, int high)
{
    int tmp = a[low]; // 记录关键字，可能会被覆盖
    double pivot = 0;
    for (size_t i = low; i <= high; i++)//这里是0居然也能跑通，找了半天错误居然是这里默认生成的代码0没修改
    {
        pivot += a[i];
    }
    pivot = pivot / (high - low + 1); // 平均值

    while (low < high)
    {
        while (low < high && a[high] >= pivot)
            --high;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low];
    }
    a[low] = tmp;
    return low; // 返回中枢节点
}

void Averge_Qsort(int R[], int low, int high)
{
    printf("%d %d\n", low, high);
    if (low < high)
    {
        int pivots = Partion(R, low, high);
        // 左边快排
        Averge_Qsort(R, low, pivots);
        // 右边快排
        Averge_Qsort(R, pivots + 1, high);
    }
}
int main(int argc, char const *argv[])
{
    int R[5] = {2, 3, 6, 4, 1};
    Averge_Qsort(R, 0, 4);
    for (size_t i = 0; i <= 4; i++)
    {
        printf("%d ", R[i]);
    }

    return 0;
}
