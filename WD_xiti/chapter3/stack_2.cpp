//括号匹配问题
#include <stdio.h>
#define Max 10
struct stack
{
    char data[Max + 1];
    int top;
};
//判空
int isempty(stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    return false;
}
//判满
int isfull(stack s)
{
    if (s.top == Max - 1)
    {
        return true;
    }
    return false;
}
//进栈
int enterstack(stack &s, char x)
{
    if (isfull(s))
    {
        printf("栈满\n");
        return -1;
    }
    s.data[++s.top] = x;
    return true;
}
//出栈
int outstack(stack &s, char &x)
{
    if (isempty(s))
    {
        printf("栈空\n");
        return false;
    }
    x = s.data[s.top--];
    return true;
}
//匹配函数
int isright(char *str)
{
    stack s;
    s.top = -1; //初始化栈
    int i = 0;
    char ans; //目标字符串
    while (str[i] != '\0')
    {
        if (str[i] == '[' || str[i] == '(' || str[i] == '{')
        {
            enterstack(s, str[i]);
        }
        else if (str[i]==']')
        {
            outstack(s, ans);
            if (ans != '[')
            {
                return -1;
            }
            
        }
        else if (str[i]==')')
        {
            outstack(s, ans);
            if (ans != ')')
            {
                return -1;
            }
            
        }
        else if (str[i]=='}')
        {
            outstack(s, ans);
            if (ans != '{')
            {
                return -1;
            }
            
        }
        i++;//指针后移
    }
    //还有判断一下是否栈空，若为空则全部匹配
    if (isempty(s))
    {
        return 1;
    }
    return -1;
    
}
int main(int argc, char const *argv[])
{
    char *str=(char *)"()[](){}";//这个我不是很懂？？
    printf("%s\n",str);
    if (!(isright(str)))
    {
        printf("不匹配\n");
    }else
        printf("匹配\n");
    
    return 0;
}
