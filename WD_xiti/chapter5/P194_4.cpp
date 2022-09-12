//逆序层次二叉树
#include <bits/stdc++.h>
using namespace std;
#define Max 10
typedef struct treenode
{
    char data;
    struct treenode *lchild, *rchild;
} treenode, *tree;
//建树
void creatree(tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (tree)malloc(sizeof(treenode));
        t->data = ch;
        t->lchild = NULL;
        t->rchild = NULL;
        creatree(t->lchild); //递归生成
        creatree(t->rchild);
    }
}
//辅助栈
typedef struct stack1
{
    struct treenode *data[Max];
    int top;
} stack1;
//判空
bool isempty(stack1 s)
{
    if (s.top == -1)
        return true;
    return false;
}
//判满
bool isfull(stack1 s)
{
    if (s.top == Max - 1)
        return true;
    return false;
}
//进栈
bool enstack(stack1 &s, treenode *p)
{
    if (isfull(s))
    {
        cout << "栈满" << endl;
        return false;
    }
    s.data[++s.top] = p;
    return true;
}
//出栈
bool outstack(stack1 &s, treenode *&p)//要引用出来,不加&输出全是G...
{
    if (isempty(s))
    {
        cout << "栈空" << endl;
        return false;
    }
    p = s.data[s.top--];
    return p;
}
//辅助队列
struct squeue1
{
    struct treenode *data[Max];
    int f, r, tag;
};
//进队
int enqueue(squeue1 &s, treenode *x)
{
    if (s.r == s.f && s.tag == 1)
    {
        cout << "队满" << endl;
        return 0;
    }
    s.data[s.r] = x;
    s.r = (s.r + 1) % Max;
    s.tag = 1;
    return true;
}
//出队
int outsqueue(squeue1 &s, treenode *&x)
{
    if (s.f == s.r && s.tag == 0)
    {
        cout << "队空" << endl;
        return 0;
    }
    x = s.data[s.f];
    s.f = (s.f + 1) % Max;
    s.tag = 0;
    return 1;
}
void solve(tree t)
{
    stack1 s;
    squeue1 q;
    treenode *p;
    if (t)
    {
        s.top = -1;
        q.f = q.r = q.tag = 0;
        enqueue(q, t);
        while (!(q.f == q.r && q.tag == 0))
        {
            outsqueue(q, p);
            enstack(s, p);
            if (p->lchild)
                enqueue(q, p->lchild);
            if (p->rchild)
                enqueue(q, p->rchild);
        }
        while (!isempty(s))
        {
            outstack(s, p);
            cout << p->data << " ";
        }
    }
}

int main(int argc, char const *argv[])
{
    tree t;
    creatree(t);
    solve(t);
    return 0;
}
