#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
//动态顺序表
typedef struct SeqList
{
    SLDataType* list;
    int size;//存储的数据个数
    int capacity;//存储空间大小
}SeqList;

void SeqListPrint(SeqList* ps);
void SeqListInit(SeqList* ps);
void SeqListCheckCapacity(SeqList* ps);
void SeqListDes(SeqList* ps);
void SeqListPushBack(SeqList* ps,SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps,SLDataType x);
void SeqListPopFront(SeqList* ps);
int SeqListFind(SeqList* ps,SLDataType);
void SeqListInsert(SeqList* ps,size_t pos,SLDataType x);
void SeqListErase(SeqList* ps,size_t pos);
void SeqListModify(SeqList* ps,size_t pos,SLDataType x);