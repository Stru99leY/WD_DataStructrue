/*
顺序表:
    1、可动态增长的数组
    2、数据在数组中存储时必须是连续的
缺点:
    1、中间或者头部的插入删除很慢，需要挪动数据，时间复杂度O(n)
    2、空间不够时，增容会有一定的消耗和空间浪费
优点:
    1、随机访问
    2、缓存命中率比较高(物理空间连续)
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//静态顺序表
/*
#define N10
typedef int SLDataType;

//顺序表，有效数据在数组中必须连续
struct Seqlist
{
    SLDataType a[10];
    int size;
};
//尾插尾删，头插头删
void SeqListpushback(struct Seqlist* p,SLDataType x);
void SeqListpopback(struct Seqlist* p);
void SeqListpushfront(struct Seqlist* p,SLDataType x);
void SeqListpopfront(struct Seqlist* p);
*/
//动态
typedef int SLDataType;
typedef struct Seqlist
{
    SLDataType *a;
    int size;
    int capacity;
} SL, Seqlist;
//初始化
void SeqlistInit(SL *p);
//检查容量
void SeqlistCapacityCheck(SL *p);
//销毁
void SeqListDestory(SL* p)
{
    free(p->a);//释放指针指向的那个空间
    p->a=NULL;//防止野指针
    p->size=p->capacity=0;
}
//打印
void SeqlistPrint(SL *p);
//尾插尾删，头插头删
void SeqListpushback(SL *p, SLDataType x);
void SeqListpopback(SL *p);
void SeqListpushfront(SL *p, SLDataType x);
void SeqListpopfront(SL *p);
//任意位置插入删除
void SeqListInsert(SL *p, int pos, SLDataType x);
void SeqListErase(SL *p, int pos);
//查找
int SeqListFind(SL *p, SLDataType x);



//初始化
void SeqlistInit(SL *p)
{
    p->a = (SLDataType *)malloc(sizeof(SLDataType) * 4);
    if (p->a == NULL)
    {
        printf("内存分配失败\n");
        exit(-1);
    }
    p->size = 0;
    p->capacity = 4;
}
//检查容量
void SeqlistCapacityCheck(SL *p)
{
    p->capacity *= 2;
    p->a = (SLDataType *)realloc(p->a, sizeof(SLDataType) * 2);
    if (p->a == NULL)
    {
        printf("扩容失败\n");
        exit(-1);
    }
}
//尾插
void SeqListpushback(SL *p, SLDataType x)
{
    assert(p);
    // check capacity
    SeqlistCapacityCheck(p);
    //在表尾部插入数据
    p->a[p->size] = x;
    p->size++;

    //直接用SeqListInsert(p,p->size,x);代替这个接口
}
//尾删
void SeqListpopback(SL *p)
{
    assert(p);
    p->a[p->size - 1] = 0;
    p->size--;
}
//头插
void SeqListpushfront(SL *p, SLDataType x)
{
    //需考虑capacity问题
    SeqlistCapacityCheck(p);
    int end = p->size - 1;
    while (end >= 0)
    {
        p->a[end + 1] = p->a[end];
        --end;
    }
    p->a[0] = x;
    p->size++;
}
//头删
void SeqListpopfront(SL *p)
{
    assert(p);
    int start = 0;
    while (start < p->size - 1)
    {
        p->a[start] = p->a[start + 1];
        ++start;
    }
    p->size--;
}
//任意位置插入
void SeqListInsert(SL *p, int pos, SLDataType x)
{
    assert(p);
    SeqlistCapacityCheck(p);
    if (pos < 0 || pos > p->size)
    {
        printf("插入位置错误\n");
        exit(-1);
    }
    int end=p->size-1;
    while (end>=pos)
    {
        p->a[end+1]=p->a[end];
        --end;
    }
    p->a[pos]=x;
    p->size++;
}
//任意位置删除
//这里可以将int 换成 size_t 就不用检查pos>=0了
void SeqListErase(SL *p, int pos)
{
    assert(p);
    assert(pos<p->size && pos >= 0 );

    int start = pos;
    while (start < p->size-1)
    {
        p->a[start]=p->a[start+1];
        ++start;
    }
    p->size--;
}
//查找
int SeqListFind(SL *p, SLDataType x)
{
    assert(p);
    int i=0;
    while (i<p->size)
    {
        if(p->a[i]==x){
            return i;
        }
        ++i;
    }
    return -1;
}
void SeqlistPrint(SL *p)
{
    for (int i = 0; i < p->size; i++)
    {
        printf("%d ", p->a[i]);
    }
    printf("\n");
}

//测试头尾插入删除
void TestSeqList1()
{
    Seqlist s;
    SeqlistInit(&s);
    SeqListpushback(&s, 1);
    SeqListpushback(&s, 2);
    SeqListpushback(&s, 3);
    SeqListpushback(&s, 4);
    SeqListpushback(&s, 2);
    SeqlistPrint(&s);

    SeqListpopback(&s);
    SeqlistPrint(&s);

    SeqListpushfront(&s, -1);
    SeqlistPrint(&s);

    SeqListpopfront(&s);
    SeqlistPrint(&s);

    SeqListInsert(&s,4,5);
    SeqlistPrint(&s);

    int pos=SeqListFind(&s,5);
    if (pos != -1)
    {
        SeqListErase(&s,pos);
    }
    
    SeqlistPrint(&s);


}

int main(int argc, char const *argv[])
{
    TestSeqList1();
    return 0;
}
