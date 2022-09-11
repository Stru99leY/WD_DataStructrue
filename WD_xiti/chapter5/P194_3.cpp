//非递归的后序遍历
#include <bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    char data;
    struct TreeNode *lchild,*rchild;
    int tag;
}TreeNode,*Tree;

void creatree(Tree &t){
    char ch;//字符类型的树
    ch = getchar();
    if(ch=='#') t= NULL;//当输出为 # 时结束子树构造
    else
    {
        t=(TreeNode *)malloc(sizeof(TreeNode));//申请空间
        t->data=ch;
        t->tag=0;
        t->lchild=NULL;
        t->rchild=NULL;
        //递归构建树
        creatree(t->lchild);
        creatree(t->rchild);
    }
    
}

void back(Tree t){
    struct TreeNode *stack[100];//辅助栈实现非递归
    int top =-1;//栈顶指针
    TreeNode *p=t;//指向树的指针
    TreeNode *x;//保持输出的结果
    while (p || top != -1)
    {
        if(p){
                top++;
                stack[top]=p;
                p=p->lchild;//遍历左子树
        }
        else{
            p=stack[top];
            if(p->rchild && p->rchild->tag==0){
                p=p->rchild;
            }
            else
            {
                p=stack[top];
                top--;
                cout<<p->data<<" ";
                p->tag=1;//标志访问过的节点
                p=NULL;//p要置为空，要不然循环不能继续下去
            }
            
        }
    }
    
}

int main(int argc, char const *argv[])
{
    Tree t;
    creatree(t);
    back(t);
    return 0;
}
