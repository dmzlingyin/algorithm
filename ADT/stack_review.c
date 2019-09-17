//Date:2019-07-16

//顺序表的类型描述
#define InitSize 50

typedef struct{
    ElemType *data;
    int length,MaxSize;
}SqList;

//动态分配
SqList L;
L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
L.length = 0;
L.MaxSize = InitSize;

//初始化操作,构造一个空表
int InitSqList(SqList &L)
{
    L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    if(L.data == NULL)
        exit(OVERFLOW);
    L.length = 0;
    L.MaxSize = InitSize;
    return OK;
}

//插入操作
int ListInsert(SqList &L,int i,ElemType e)
{
    //判断i的合法性
    if(i < 1 || i > L.length+1)
        return ERROR;
    if(L.length >= L.MaxSize)//保险起见，>=
        return ERROR;
    for(int k = L.length;k >= L.length-i;k--)
    {
        L.data[k] = L.data[k - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return OK;
}

//删除操作
int ListDelete(SqList &L,int i,ElemType e)
{
    //判断位置的合法性
    if(i < 1 || i > L.length)
        return ERROR;
    if(L.length == 0)
        return ERROR;
    e = L.data[i - 1];
    for(int k = i;k < L.length;k++)
    {
        L.data[k - 1] = L.data[k];
    }
    L.length--;
    return OK;
}

//获取表L的第i个位置的元素

int GetElem(SqList L,int i,ElemType &e)
{
    //判断i是否合法
    if(i < 1 || i > L.length)
        return ERROR;
    e = L.data[i - 1];
    return OK;
}

//查找第一个等于e的元素，并返回其位置
int LocateElem(SqList L,ElemType e)
{
    int i;
    for(i = 0;i < L.length;i++)
    {
        if(L.data[i] == e)
            return i+1;

    }
    return 0;
}

//销毁顺序表
int DestroyList(SqList &L)
{
    if(L.data)
        frdd(L.data);
    L.length = 0;
    L.MaxSize = 0;
    return 0;
}


//清空顺序表
int ClearList(SqList &L)
{
    L.length = 0;
    return OK;
}

//获取顺序表的长度
int GetLength(SqList L)
{
    return L.length;
}

//判断当前顺序表是否为空
int Empty(SqList L)
{
    if(L.length == 0)
        return 1;
    else
        return 0;
}

//按顺序输出所有的值
void PrintList(SqList L)
{
    int i;
    for(i = 0;i < L.length;i++)
    {
        printf("%d\n",L.data[i]);
    }
}



typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//初始化带头结点的单链表
int InitLinkList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if(!L)
        return ERROR;
    L->next = NULL;
    return OK;
}

//头插法
int CreateList1(LinkList &L)
{
    LinkList P = L;
    LinkList T;
    for(int i = 0;i <100;i++)
    {
        T = (LinkList)malloc(sizeof(LNode));
        T->next = P->next;
        P->next = T;
    }
    return OK;
}

//尾插法
int CreateList2(LinkList &L)
{
    LinkList P = L;
    LinkList T;
    for(int i = 0;i < 100;i++)
    {
        T = (LinkList)malloc(sizeof(LNode));
        if(!T)
            return ERROR;
        T->next = NULL;
        P-next = T;
        P = T;
    }
    return OK;

}

//按序号查找节点值
LinkList GetElem(LinkList L,int i)
{
    int j = 1;
    LinkList p = L->next;指向首节点
    if(i == 0)
        return L;
    if(i < 1)
        return ERROR;
    while(p && j<i)
    {
        p = p->next;
        j++;
    }
    return p;
}


//按值查找节点值
LinkList LocateElem(LinkList L,ElemType e)
{
    LinkList p = L->next;//指向头结点
    while(p && p->data!= e)
    {
        p = p->next;
    }
    return p;
}

//插入节点操作 将值为x的新节点插入到链表的第i个位置上

p = GetElem(L,i-1);
s->next = p->next;
p->next = s;

//删除第i个位置上的节点
LinkList s;
p = GetElem(L,i-1);
s = p->next;
p->next = s->next;
free(s);

//求单链表L的长度
int GetLength(SqList L)
{
    int j = 0;
    LinkList p = L->next;
    while(p)
    {
        j++;
        p = p->next;
    }
    return j;
}

/******************************双链表*********************************/
//类型描述
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

//双链表的插入操作
//s为要插入的节点
s->next = p->next;
p->next->prior = s;
s->prior = p;
p->next = s;

//双链表的删除操作
s->next = p->next;
s->next->prior = p;
free(s);


