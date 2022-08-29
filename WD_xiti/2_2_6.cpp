#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int data;
    struct lnode *next;
} lnode, *linklist;
int a[4] = {4, 2, 9, 1};
int n = 4;

void build_list(linklist &L)
{
    //尾插法建立
    L = (linklist)malloc(sizeof(lnode));
    lnode *r = L, *s;
    for (int i = 0; i < n; i++)
    {
        s = (lnode *)malloc(sizeof(lnode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
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

void sortlist(linklist &L)
{
    lnode *p = L->next, *r = p->next, *f;
    p->next = NULL;
    p = r;
    while (p)
    {
        r = p->next;
        f = L;
        while (f->next != NULL && f->next->data < p->data)
            f = f->next; //如果f->next的值比上面剩下链表p的值要小的话，f后移
        p->next = f->next;
        f->next = p;
        p = r;//移回去p
    }
}
int main(int argc, char const *argv[])
{
    linklist L;
    build_list(L);
    disp(L);
    sortlist(L);
    disp(L);
    return 0;
}
