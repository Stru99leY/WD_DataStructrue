//交换二叉树左右树
/*
            A           A
          /   \       /   \
         B     C     C     B
        / \   / \   / \   / \
       D   E F   G G   F E   D
ABD##E##CF##G##    -->   ACGDBED
*/
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
    ch = getchar();
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
//交换左右子树
void swap(tree &t)
{
    treenode *p;
    if (t)
    {
        swap(t->lchild);
        swap(t->rchild);
        p = t->rchild;
        t->rchild = t->lchild;
        t->lchild = p;
    }
}
void disp(tree t)
{
    if (t)
    {
        cout << t->data << " ";
        disp(t->lchild);
        disp(t->rchild);
    }
}

int main(int argc, char const *argv[])
{
    tree t;
    buildtree(t);
    cout << "交换后二叉树的前序序列为:" << endl;
    swap(t);
    disp(t);
    return 0;
}
