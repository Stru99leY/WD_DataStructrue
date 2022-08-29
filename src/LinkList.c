#include <stdio.h>
#include <stdlib.h>

typedef int LLDataType;

typedef struct SListNode
{
    LLDataType date;
    struct SListNode *next;
} SLNode;

void SlistPushBack(SLNode **ppList, LLDataType x); //二级指针修改
void SlistPopBack(SLNode **ppList);
void SlistPushFront(SLNode **ppList, LLDataType x);
void SlistPopFront(SLNode **ppList);
void SlistPrint(SLNode *pList);
void SlistInsertAfter(SLNode* pos,LLDataType x);
void SlistEraseAfter(SLNode* pos);
SLNode* SlistFind(SLNode* pList,LLDataType x);
SLNode *SlistcreateNode(LLDataType x);

//创建新节点
SLNode *SlistcreateNode(LLDataType x)
{
    SLNode *newNode = (SLNode *)malloc(sizeof(LLDataType));
    if (newNode == NULL)
    {
        printf("分配内存失败\n");
        exit(-1);
    }
    newNode->date = x;
    newNode->next = NULL;
    return newNode;
}
//输出
void SlistPrint(SLNode *pList)
{
    SLNode *cur = pList;
    while (cur != NULL)
    {
        printf("%d->", cur->date);
        cur = cur->next;
    }
    printf("NULL\n");
}
//尾插
void SlistPushBack(SLNode **ppList, LLDataType x)
{
    SLNode *newNode = SlistcreateNode(x);
    if (*ppList == NULL)
    {
        *ppList = newNode;
    }
    else
    {
        //找尾
        SLNode *tail = *ppList;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        //申请新节点，存放待插入数据
        SlistcreateNode(x);
        //将tail指向新数据
        tail->next = newNode;
    }
}
//尾删
void SlistPopBack(SLNode **ppList)
{
    // 1、空
    // 2、一个结点
    // 3、一个以上结点
    if (*ppList == NULL)
    {
        return;
    }
    else if ((*ppList)->next == NULL)  // * 与 -> 同优先级，因先解引用ppList
    {
        free(*ppList);
        *ppList = NULL;
    }
    else
    {
        SLNode *prev = NULL;
        SLNode *tail = *ppList;
        while (tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }

        free(tail);
        prev->next = NULL;
    }
}
//头插
void SlistPushFront(SLNode **ppList, LLDataType x)
{
    SLNode *newNode = SlistcreateNode(x);
    newNode->next = *ppList; //指向头节点指向的那个
    *ppList = newNode;       //新加入的节点变成头节点
}
//头删
void SlistPopFront(SLNode **ppList)
{
    if (*ppList == NULL)
    {
        return;
    }
    else
    {
        SLNode* next = (*ppList)->next;
        free(*ppList);
        *ppList = next;
    }
    
    
}
//查找
SLNode* SlistFind(SLNode* pList,LLDataType x)
{
    SLNode* cur = pList;
    while (cur)
    {
        if(cur->date == x)
        {
            return cur;
        }
        cur=cur->next;
    }
    return NULL;
}
//插入
void SlistInsertAfter(SLNode* pos,LLDataType x)
{
    SLNode* newnode = SlistcreateNode(x);
    newnode->next = pos->next;
    pos->next  = newnode;
}
//删除
void SlistEraseAfter(SLNode* pos)
{
    if (pos->next)
    {
        SLNode* next = pos->next;
        SLNode* nextnext = next->next;
        pos->next = next->next;
        free(next);
    }
    
}
int main(int argc, char const *argv[])
{
    SLNode *pList = NULL;
    SlistPushBack(&pList, 1);
    SlistPushBack(&pList, 2);
    SlistPushBack(&pList, 3);
    SlistPushBack(&pList, 4);

    SlistPrint(pList);

    SlistPopBack(&pList);
    SlistPopBack(&pList);
    SlistPopBack(&pList);
    SlistPopBack(&pList);
    SlistPrint(pList);

    SlistPushFront(&pList,5);
    SlistPushFront(&pList,6);
    SlistPushFront(&pList,7);
    SlistPushFront(&pList,8);
    SlistPrint(pList);

    // SlistPopFront(&pList);
    // SlistPopFront(&pList);
    // SlistPopFront(&pList);
    // SlistPopFront(&pList);
    // SlistPrint(pList);

    SLNode* pos=    SlistFind(pList,5);
    if (pos)
    {
        pos->date=30;
    }
    SlistPrint(pList);
    SlistInsertAfter(pList,6);
    SlistPrint(pList);
    SlistEraseAfter(pList);
    SlistPrint(pList);

    return 0;
}
