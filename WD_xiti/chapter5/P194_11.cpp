//删除给定值为x的节点并释放相应空间
/*
            A
          /   \
         B     C
        / \   / \
       D   E F   G

*/

#include <bits/stdc++.h>
using namespace std;

typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;

//建树
void buildtree(tree &t){
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else{
        t=(treenode *)malloc(sizeof(treenode));
        t->data=ch;
        t->lchild=NULL;
        t->rchild=NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//递归释放节点
void Release(tree &t){
    if(!t) return;
    Release(t->lchild);
    Release(t->rchild);
    free(t);
}
//前序遍历
void delete_x(tree &T,char x){
    if(T==NULL) return;
    if(T->data==x){
        //递归释放节点
        Release(T);
        //手动设置设置为NULL
        T=NULL;//free并不是物理内存释放所以需要手动置空
    }
    if(T!=NULL){
        //递归找左右孩子
        delete_x(T->lchild,x);
        delete_x(T->rchild,x);
    }
}
//输出
void disp(tree t){
    if(t){
        cout<<t->data<<" ";
        disp(t->lchild);
        disp(t->rchild);
    }
}

int main(int argc, char const *argv[])
{
    tree t;
    buildtree(t);
    delete_x(t,'B');
    disp(t);
    return 0;
}
