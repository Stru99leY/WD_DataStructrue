//分解链表为两条奇偶序号的链表
#include <stdio.h>
#include <stdlib.h>
typedef struct lnode
{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={2,5,6,7,9};
int n=5; 
void buildlist(linklist &L)
{
    L=(linklist)malloc(sizeof(lnode));
    lnode *r=L,*s;
    for (int i = 0; i < n; i++)
    {
        s=(lnode *)malloc(sizeof(lnode));//给s分配空间
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
    
}
linklist L2;//新表
void cut(linklist &L1 )
{
    L2=(linklist)malloc(sizeof(lnode));
    L2->next=NULL;
    lnode *r1=L1,*r2=L2,*p=L1->next;
    L1->next=NULL;
    int i=0;//计数，奇偶数
    while (p)
    {
        i++;
        if (i%2==0)
        {
            //偶数放在l2
            r2->next=p;
            r2=p;
        }
        else
        {
            r1->next=p;
            r1=p;
        }
        p=p->next;
    }
    r1->next=NULL;
    r2->next=NULL;
}

int main(int argc, char const *argv[])
{
    linklist L1;
    buildlist(L1);
    printf("之前：\n");
    disp(L1);
    cut(L1);
    printf("之后\n");
    disp(L1);
    printf("L2为\n");
    disp(L2);
    return 0;
}
