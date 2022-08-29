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

void Delete(linklist &L,int x,int y){
    lnode *pr=L,*p=L->next;
    while (p)
    {
        if (p->data>x && p->data<y){
            pr->next=p->next;
            free(p);
            p=pr->next;
        }
        else
        {
            pr=p;
            p=p->next;
        }
        
    }
    

}
int main(int argc, char const *argv[])
{
    linklist L;
    build_list(L);
    disp(L);
    Delete(L,2,6);
    disp(L);
    return 0;
}
