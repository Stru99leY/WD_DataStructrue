#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[4]={1,2,3,4};
int n=4;

void build_list(linklist &L){
    //尾插法建立
    L=(linklist)malloc(sizeof(lnode));
    lnode *r=L,*s;
    for (int i = 0; i < n; i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data = a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}

void disp(lnode *L)
{
    lnode *s = L->next;
    while (s)
    {
        printf("%  d", s->data);
        s = s->next;
    }
    printf("\n");
}
void reverse(linklist &L){
    lnode *p=L->next,*r;
    L->next=NULL;
    while (p)
    {
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
    

}
/*
错误的
void My_rev(linklist &L){
    lnode *p=L->next,*s=p->next,*q=s->next;
    while (p)
    {
        p->next=NULL;
        p=s->next;
        q=q->next;
        p=s;
        s=q;
    }
    q->next=s;
}
*/
int main(int argc, char const *argv[])
{
    linklist L;
    build_list(L);
    printf("逆置之前：\n");
    disp(L);
    printf("逆置之后：\n");
    //reverse(L);
    disp(L);
    return 0;
}
