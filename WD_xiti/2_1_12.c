#include <stdio.h>
/*
把第一个设为待选主元素，然后与其后面的元素做比较。相等计数+1，否则-1，当计数<0时选取下一个为待选主元素
因为上述方法是假设有主元素的情况，所以遍历一遍后，再重新遍历一遍找有几个与待选主元素相同的数
若>n/2个则存在主元素
*/
int Find_Mid(int A[], int n)
{
    int count = 1, mid;
    mid = A[0];//将第一个元素设置为待选主元素
    for (int i = 0; i < n; i++)
    {
        if (mid == A[i])
        {
            count++;//如果与待选主元素相等，计数++
        }
        else
        {
            //如果不等则计数-1
            if (count > 0)
            {
                count--;
            }
            //当计数<0时重新选取下一个元素为主元素，并将将计数器重置为1
            else
            {
                mid = A[i];
                count = 1;
            }
        }
    }
    //遍历一遍找出与待选主元素相同的个数
    if (count>0)
    {
        for (int i = count = 0; i < n; i++)
        {
            if (A[i]==mid)
            {
                count++;
            }
            
        }
    }
    //若>n/2满足题意
    if (count>n/2)
    {
        return mid;
    }else
        return -1;
}
int main(void)
{
    int a[] = {0, 5, 5, 3, 5, 7, 5, 5};
    int a1[] = {0, 5, 5, 3, 5, 1, 5, 7};
    printf("%d\n",Find_Mid(a,8));
    printf("%d\n",Find_Mid(a1,8));
    
    return 0;
}