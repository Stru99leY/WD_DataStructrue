//两栈共享一片内存，分别进行进出栈操作
#include <stdio.h>
#include <stdlib.h>
#define Max 50
typedef struct 
{
    int data[Max];
    int top[2];
}stack1;
stack1 s;
//进栈
int push(int i,int x)
{
    //对栈0 或者 1进行操作，否则报错
    if(i!=0 && i!=1){
        printf("无栈");
        return -1;
    }
    if (s.top[1]-s.top[0]==1)
    {
        printf("栈满");
        return -1;
    }
    if (i==0)
    {
        s.data[++s.top[0]]=x;
    }else s.data[--s.top[1]]=x;
    return 1;
}
//出栈
int pop(int i)
{
    if(i!=0 && i!=1)
    {
        printf("无栈");
        return -1;
    }
    if (i==0)
    {
        if (s.top[0]==-1)
        {
            printf("0号栈空");
            return -1;
        }
        return s.data[s.top[0]--];
        
    }
    else
    {
                if (s.top[0]==Max)
        {
            printf("1号栈空");
            return -1;
        }
        return s.data[s.top[1]++];
        
    }
    
}
int main(int argc, char const *argv[])
{
    s.top[0]=-1,s.top[1]=Max;
    if(push(0,1)!=-1);//对0号栈进栈1
    printf("0号栈进栈成功\n");
    int x=pop(0);//0号出栈
    if(x!=-1) printf("0号栈出栈元素为:%d\n",x);
    int y=pop(0);
    return 0;
}
