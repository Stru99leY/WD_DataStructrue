//求先序遍历中第K个节点的值
/*
            A
          /   \
         B     C
        / \   / \
       D   E F   G

*/
#include <iostream>
using namespace std;
//树结构体
typedef struct treenode
{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
//建树
void buildtree(tree &t){
    char ch;
    ch=getchar();
    if(ch =='#') t=NULL;
    else{
        t=(treenode *)malloc(sizeof(treenode));
        t->data=ch;
        t->lchild=NULL;
        t->rchild=NULL;
        //递归生成左右子树
        buildtree(t->lchild);
        buildtree(t->rchild);

    }
}
//先序遍历 递归

//计数器
int i=1;
//字符 全局
char ch;
char PreNode(tree t,int k){
    if(t==NULL) return '#';
    if(i==k) return t->data;
    i++;
    ch=PreNode(t->lchild,k);//接收左子树遍历的节点
    if(ch!='#')//如果未遍历完左子树就找到直接返回该节点 
        return ch;
    ch=PreNode(t->rchild,k);
    return ch;
}
int main(int argc, char const *argv[])
{
    tree t;
    buildtree(t);
    cout<<PreNode(t,5)<<endl;
    return 0;
}
