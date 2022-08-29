//按递增次序输出链表元素
#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={3,2,5,8,7};
int n=5;

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

void Delete_min(linklist &L){
while (L->next != NULL)
    {
        lnode *pr=L,*p=L->next;
        while (p->next!=NULL)
        {
            if(pr->next->data>p->next->data)
                pr=p;//找值最小节点的前驱
            p=p->next;
        }
        printf("%  d",pr->next->data);
        lnode *q=pr->next;
        pr->next=q->next;
        free(q);
    }
    free(L);//释放头节点
    
}
int main(int argc, char const *argv[])
{
    linklist L;
    build_list(L);
    Delete_min(L);
    return 0;
}
