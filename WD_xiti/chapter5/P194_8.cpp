//二叉树的双分支节点个数
/*
            A
          /   \
         B     C
        / \   / \
       D   E F   G
前序序列 ABD##E##CF##G##
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
void buildtree(tree &t){
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        t=(treenode *)malloc(sizeof(tree));
        t->data=ch;
        t->lchild=NULL;
        t->rchild=NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
    
}
int num(tree t){
    if(!t) return 0;
    //树有左右孩子时递归计算
    else if(t->lchild && t->rchild) return num(t->lchild)+num(t->rchild)+1;//+1代表还要加上根节点
    else return num(t->lchild)+num(t->rchild);//根节点不是双分支节点
}

int main(int argc, char const *argv[])
{
    tree t;
    buildtree(t);
    cout<<"该二叉树中双分支节点个数为:"<<num(t)<<" "<<endl;
    return 0;
}
