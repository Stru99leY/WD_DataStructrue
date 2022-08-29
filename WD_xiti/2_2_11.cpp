//头插法分离奇偶序号链表
#include <stdio.h>
#include <stdlib.h>
typedef struct lnode
{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[10]={1,2,3,4,5,6,7,8,9,10};
int n=10;
void buildlist(linklist &L)
{
    L=(lnode *)malloc(sizeof(lnode));
    lnode *r=L,*s;
    for (int i = 0; i < n; i++)
    {
        s=(linklist)malloc(sizeof(lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
//打印
void disp(linklist L)
{
    lnode *s=L->next;
    while (s)
    {
        printf("% d",s->data);
        s=s->next;
    }
    printf("\n");
}
linklist L2;
void cut_list(linklist &L1)
{
    L2=(linklist)malloc(sizeof(lnode));
    L2->next=NULL;
    lnode *p=L1->next,*q,*r=L1;
    while (p)
    {
        r->next=p;
        r=p;
        p=p->next;//p指向第二个元素
        if (p!=NULL) q=p->next;//q指向p的后继，防止断链
        p->next=L2->next;
        L2->next=p;
        p=q;
    }
    r->next=NULL;
}
int main(int argc, char const *argv[])
{
    linklist L1;
    buildlist(L1);
    printf("之前：\n");
    disp(L1);
    cut_list(L1);
    printf("L1为\n");
    disp(L1);
    printf("L2为\n");
    disp(L2);
    return 0;
}
