//队列逆置通过辅助栈
#include <stdio.h>
#include <stdlib.h>
#define Max 10
struct stack
{
    int data[Max];
    int top;
};
struct squeue
{
    int data[Max];
    int r,f,tag;
};
//进队
int entersqueue(squeue &s,int x)
{
    if(s.r==s.f && s.tag==1)
    {
        printf("队满进队失败\n");
        return false;
    }
    s.data[s.r]=x;
    s.r=(s.r+1)%Max;
    s.tag=1;
    return true;
}
//出队
int outsqueue(squeue &s,int &x)
{
    if(s.f==s.r&&s.tag==0){
        printf("队空");
        return 0;
    }
    x=s.data[s.r];
    s.r=(s.r+1)%Max;
    s.tag=0;
    return true;
}
//入栈
int enterstack(stack &s,int x){
    if(s.top==Max-1){
        printf("栈满");
        return false;
    }
    s.data[++s.top]=x;
    return true;
}
//出栈
int outstack(stack &s,int &x){
    if (s.top==-1)
    {
        printf("栈空");
        return 0;
    }
    x=s.data[s.top--];
    return 1;
    
}
//输出
void disp(squeue s)
{
    for (int i = 0; i < Max; i++)
    {
        printf("%  d",s.data[s.f]);
        s.f=(s.f+1)%Max;
    }
    putchar('\n');
    
}
int main()
{
    squeue s1; 
    stack s2;
    s1.f=0,s1.r=0,s1.tag=0;//队初始化
    s2.top =-1;//初始化
    for (int i = 0; i < Max; i++)
    {
        entersqueue(s1,i);

    }
    disp(s1);
    int x=0;
    while (!(s1.f==s1.r && s1.tag==0))//队非空
    {
        //出队
        outsqueue(s1,x);
        enterstack(s2,x);

    }
    while (!(s2.top==-1))//栈非空
    {
        //进栈
        outstack(s2,x);
        entersqueue(s1,x);
    }
    disp(s1);
    return 0;
}