//非递归层次遍历计算树的高度
/***
 *使用辅助队列将层次遍历的元素入队
 * 设置个int l指向每层的最后一个元素
 * 当r==l时遍历完一层
***/
#include <bits/stdc++.h>
using namespace std;
typedef struct treenode
{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
//建树
void creatree(tree &t){
    char ch;
    ch = getchar();
    if(ch=='#') t=NULL;
    else
    {
        t=(treenode *)malloc(sizeof(tree));
        t->data=ch;
        t->lchild=NULL;
        t->rchild=NULL;
        creatree(t->lchild);
        creatree(t->rchild);
    }
    
}
//计算深度
int dept(tree t){
    if(!t) return 0;
    treenode *q[10];//辅助队列
    int f=-1,r=-1;
    int L=0,ans=0;//L指向每层的最后一个节点，ans为深度
    q[++r]=t;//头节点入队
    treenode *p;//用于出队
    while (f<r)
    {
        p=q[++f];//出队
        if(p->lchild) q[++r]=p->lchild;
        if(p->rchild) q[++r]=p->rchild;
        if(L==f){
            ans++;
            L=r;
        }    
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    tree t;
    creatree(t);
    cout<<"树的高度为: "<<dept(t)<<endl;
    return 0;
}
