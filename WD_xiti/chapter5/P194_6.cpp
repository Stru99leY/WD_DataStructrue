/*
先序中序构造二叉树
            A
          /   \
         B     C
        / \   /
       D   E F
*/
#include <bits/stdc++.h>
using namespace std;
typedef struct treenode
{
    char data;
    struct treenode *lchild, *rchild;
} treenode, *tree;
int pos; //指向先序A数组
tree build(char a[], char b[], int s, int e)
{
    // s,e为中序数组构造二叉树的区间
    if (s <= e)
    {
        treenode *root = (treenode *)malloc(sizeof(tree)); //构建头节点
        root->data = a[pos];
        int i;
        for (i = s; i < e; i++)
        {
            if (b[i] == root->data) //在b中找头节点位置
                break;
        }
        pos++; //后移找下一个
        //递归生成 注意区间
        root->lchild = build(a, b, s, i - 1);
        root->rchild = build(a, b, i + 1, e);
        return root;
    }
    return NULL;
}
void disp(tree t)
{
    if (t)
    {
        disp(t->lchild);
        disp(t->rchild);
        cout << t->data << " ";
    }
}
int main(int argc, char const *argv[])
{
    char a[] = {'A', 'B', 'D', 'E', 'C', 'F'}; //先序序列
    char b[] = {'D', 'B', 'E', 'A', 'F', 'C'}; //中序序列
    tree root = build(a, b, 0, 5);
    cout << "后序序列为:" << endl;
    disp(root);
    return 0;
}
