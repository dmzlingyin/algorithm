/*
Author:Lingyin
Date:2019-04-25
单链表　　增　删　改　查
*/

//单链表的的存储结构
typedef struct Node
{
    ElemType data;
    struct Node * next;
}Node,LinkList;//结构体，结构体指针

//查找元素
//获取第i个元素，并将值返回到ｅ
Status GetElem(LinkList L,int i,ElemType &e)
{
    //L指向头节点
    LinkList p = L->next;
    int j = 1;//计数器
    while(p && j<i)
    {
        p = p->next;//指针向后移动
        ++j;
    }

    if(!p || j>i)
        return Error;
    
    *e = p->data;
    return Ok;
}

//插入
Status ListInsert(LinkList L,int i,ElemType &e)
{
    LinkList p = L;//指向头节点
    int j = 1;
    while(p && j<i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i)
        return Error;
    
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return Ok;
}

//删除
Status ListDelete(LinkList L,int i,ElemType &e)
{
    LinkList = L;
    int j = 1;
    while( p->next && j<i)
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j>i)
        return Error;

    s = p->next; 
    *e = s->data;
    p->next = s->next;
    free(s);
    return Ok;
}

//创建
//逆向建立，从表尾到表头
LinkList ListCreate(int n)
{
    L = (LinkList)malloc(sizeof(Node));
    L->next = Null;//创建头节点

    for(int i=0;i<n;i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->next = L->next;
        p->data = i;
        L->next = p;
    }
    return L;
}

//正向创建
LinkList ListCreate(int n)
{
    L = (LinkList)malloc(sizeof(Node));
    L->next = Null;//创建头节点
    LinkList N = L;
    for(int i=0;i<n;i++)
    {
        p = (LinkList)malloc(sizeof(Node))
        N->next = p;
        p->data = i;
        p->next = null;
        N= p;
    }
    return L;//返回头指针
}

Status ListMerge(LinkList La,LinkList Lb,LinkList Lc)
{

    //重点:不要动头节点指针，用中间表量来代替
    //La,Lb,Lc分别为三个链表的头节点指针．Ｌa,Lb的值按非递减排列
    LinkList pa = La->next;//pa指向第一个节点
    LinkList pb = Lb->next;//pb指向第一个节点
    Lc = La;
    pc = Lc;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    
    pc->next = pa? pa:pb;
    free(Lb);

}


