//将二叉树的叶节点从左到右顺序连成一个单链表
/*
            A
          /   \
         B     C
        / \   / \
       D   E F   G
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct treenode 
{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
void buildtree(tree &t){
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        t=(treenode *)malloc(sizeof(treenode));
        //赋值
        t->data=ch;
        t->lchild=NULL;
        t->rchild=NULL;
        //递归生成
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
    
}
//全局 头节点 前驱节点 类型仍然是树结点的一个结构体 通过rchild连接起来
tree head=(treenode *)malloc(sizeof(treenode)),pre=NULL;
//中序遍历
tree InOrder(tree t)
{
    //递归条件节点不为空
    if (t)
    {
        //将根节点的左孩子作为参数 一直递归向左延伸
        InOrder(t->lchild);
        //找到叶子节点
        if(t->lchild==NULL && t->rchild==NULL){
            //如果是第一个
            if(pre==NULL){
                //头节点赋值
                head=t;
                //保留前驱节点 前驱节点为当前的一个节点 保证后面再次遇到叶子节点的时候知道前节点是谁
                pre=t;
            }
            //若不是第一个
            else
            {
                //将前驱节点的右指针指向当前节点
                pre->rchild=t;
                //更新前驱节点
                pre=t;
            }
            
        }
        //递归右子树
        InOrder(t->rchild);
        //右子树递归完成后将最后一个节点右指针指向空
        pre->rchild=NULL;
    }
    return head;
    
}

int main(int argc, char const *argv[])
{
    tree t;
    buildtree (t);
    InOrder(t);
    while (head)
    {
        cout<<head->data<<"->";
        if(head->rchild==NULL) cout<<"NULL"<<endl;
        head=head->rchild;
        
    }
    
    return 0;
}
