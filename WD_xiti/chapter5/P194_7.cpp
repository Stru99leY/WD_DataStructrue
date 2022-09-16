/* 
判断树是否为完全二叉树
1.完全二叉树，若节点无左孩子则必无右孩子
2.节点缺孩子所有后继必无孩子
完全:ABD##E##CF##G##
非完全:ABD##CE##F##
*/
#include <bits/stdc++.h>
using namespace std;
#define Max 15
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
        t=(tree)malloc(sizeof(tree));
        t->data=ch;
        t->lchild=NULL;
        t->rchild=NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
    
}
struct squeue
{
    struct treenode *data[Max];
    int f,r,tag;
};
//判空
bool isempty(squeue s){
    if(s.f==s.r&&s.tag==0) return true;
    return false;
}
//判满
bool isfull(squeue s){
    if(s.f==s.r&&s.tag==1) return true;
    return false;
}
//进队
bool enter(squeue &s,treenode *p)
{
    if(isfull(s)) return false;
    s.data[s.r]=p;
    s.r=(s.r+1)%Max;
    s.tag=1;
    return true;
}
//出队
bool out(squeue &s,treenode *&p)//记得带引用
{
    if(s.f==s.r&&s.tag==0) return false;
    p=s.data[s.f];
    s.f=(s.f+1)%Max;
    s.tag=0;
    return true;
}
//判断是否为完全二叉树
bool isok(tree t){
    squeue s;
    s.f=s.r=s.tag=0;//初始化
    bool flag=true,ans=true;//flag判断是否有孩子
    if(t==NULL) ans=true;//空树也是完全二叉树
    enter(s,t);
    treenode *p;
    while (!isempty(s))
    {
        out(s,p);
        if(!p->lchild){
            flag=false;
            if (p->rchild) ans= false;//无左孩子但有右孩子非完全二叉树
            
        }else
        {
            if(flag)//之前不存在缺孩子节点
            {
                enter(s,p->lchild);
                if(p->rchild)   enter(s,p->rchild);
                else flag=false;
            }else//之前存在缺孩子节点
                ans=false;
        }
        
    }
    return ans;
    
}

int main(int argc, char const *argv[])
{
    tree t;
    buildtree(t);
    if(isok(t)) cout<<"yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
