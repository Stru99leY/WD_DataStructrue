//找公共节点
#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={3,2,5,8,7};
int b[4]={1,5,8,7};
int n1=5,n2=4;

void build_list(linklist &L,int aa[],int n){
    //尾插法建立
    L=(linklist)malloc(sizeof(lnode));
    lnode *r=L,*s;
    for (int i = 0; i < n; i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data = aa[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
//算链表长度
int length(linklist L){
    int k=0;
    lnode *s=L->next;
    while (s)
    {
        k++;
        s=s->next;
    }
    return k;
}
//找公共节点
lnode *find_common(linklist L1,linklist L2){
    int len1=length(L1);int len2=length(L2);
    int dist=0;
    linklist long1,short1;
    if (len1>len2)
    {
        long1=L1->next;
        short1=L2->next;
        dist=len1-len2;
    }else
    {
        long1=L2->next;
        short1=L1->next;
        dist=len2-len1;
    }
    while (dist--)
    {
        long1=long1->next;//使两个链表开始位置同步
    }
    while (long1)
    {
        if(long1->data==short1->data && long1->next->data==short1->next->data) return long1;
        else{
            long1=long1->next;
            short1=short1->next;
        }
    }
    return NULL;
    
    

}
void disp(lnode *L)
{
    lnode *s = L;
    while (s)
    {
        printf("%  d", s->data);
        s = s->next;
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    linklist L1,L2;
    build_list(L1,a,n1);
    build_list(L2,b,n2);
    linklist L3=find_common(L1,L2);
    disp(L3);
    return 0;
}
