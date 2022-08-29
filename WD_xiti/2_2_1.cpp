#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;
int a[4] = {1, 2, 3, 4};
int n = 4;
void head_insert(LNode *L)
{
    LNode *s, *r = L;
    r->data = a[0];
    if (n == 1)
        r->next = NULL; //当只有一个节点时
    else
    {
        for (int i = 1; i < n; i++)
        {
            s = (LNode *)malloc(sizeof(LNode));
            s->data = a[i];
            r->next = s; // s做r的后继
            r = r->next;
        }
        r->next=NULL;
    }
}
void Print(LNode *L)
{
    LNode *s = L;
    while (s)
    {
        printf("%  d", s->data);
        s = s->next;
    }
    printf("\n");
}

void delete_x(LNode *&L, int x)
{
    if (L == NULL)
        return;
    LNode *p;
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        delete_x(L, x);
    }
    else
        delete_x(L->next, x);
}

int main(int argc, char const *argv[])
{
    LNode list;
    LNode *L = &list;
    head_insert(L);
    Print(L);
    delete_x(L, 2);
    Print(L);
    return 0;
}
