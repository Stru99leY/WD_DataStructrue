//判断二叉树是否相似

#include <bits/stdc++.h>
using namespace std;
typedef struct treenode
{
    char data;
    struct treenode *lchild, *rchild;
} treenode, *tree;

void buildtree(tree &t)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        t = NULL;
    else
    {
        t = (treenode *)malloc(sizeof(treenode));
        t->data = ch;
        t->lchild = NULL;
        t->rchild = NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//递归比较子树 空+空=1 空+非空=0
int similar(tree t1, tree t2)
{
    int left, right;
    if (t1 == NULL && t2 == NULL)
        return 1;
    else if (t1 == NULL || t2 == NULL)
        return 0;
    else
    {
        left = similar(t1->lchild, t2->lchild);
        right = similar(t1->rchild, t2->rchild);
    }
    if (right && left)
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    tree t1, t2;
    buildtree(t1);
    buildtree(t2);
    cout << similar(t1, t2) << endl;
    return 0;
}
