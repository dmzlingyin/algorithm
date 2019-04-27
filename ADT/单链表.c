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
    L->next = NULL;//创建头节点

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
        p->next = NULL;
        N= p;
    }
    return L;//返回头指针
}

//合并两个链表
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


//单向循环链表,含有头节点
//为参考别人的代码，自己的实现起来太麻烦．
void CreatList(int n)
{
   LinkList L = (LinkList)malloc(sizeof(Node));//创建头节点
   L->next = NULL;
   LinkList s = L;
   
   LinkList p = (LinkList)malloc(sizeof(Node));//第一个节点
   L->next = p;//头节点指向第一个节点
   s = p;
   for(int i=1;i < n;i++)
   {
        LinkList p = (LinkList)malloc(sizeof(Node));
        p->next = L->next;
        s->next = p;
        s = s->next;


   }

}

//单向循环链表，无头节点
//参考网上的源代码
void CreatList(int n)
{
    //创建第一个节点
    LinkList h = (LinkList)malloc(sizeof(Node));
    h->data = 0;
    h->next = h;//指向自己

    for(int i = 1;i < n;i++)
    {

        LinkList p = (LinkList)malloc(sizeof(Node));
        p->next = h->next;
        h->next = p;
        h = h->next;//ｈ向右移动．

    }
    h = h->next;//上面的循环遍历完成后，h指向的是最后一个节点，所以，还得让h指向第一个节点．向右移动一个．

}

/************************************************************************************************************
 * 双向链表的操作
 * Author:Lingyin
 * Date:2019-04-27
 * 
*************************************************************************************************************/

//线性表的双向链表存储结构
typedef struct DuLNode
{
    ElemType    data;
    struct DuLNode *prior;//前向指针
    struct DuLNode *next;//后向指针
}DuLNode,*DuLinkList;

//双向链表和单向链表的不同之处在于插入和删除操作，其他都大同小异

Status InsertList(DuLinkList L,int i,ElemType e)
{
    //含有头节点，在第i个位置之前插入ｅ
    //i的合法值是1<= i <= 表长 + 1
    if(!(p = GetElemP_DuL(L,i)))//i为不合法值
        return ERROR;

    if(!(s = (DuLinkList)malloc(sizeof(DuLNode))));
        return ERROR;//动态获取内存失败
    s->data = e;
    s->next = p->next;//p为第i个元素之前的位置
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    
    return OK;
}

//删除节点
Status DeleteList_DuL(DuLinkList L,int i,ElemType *e)
{
    //i的合法值为1<= i <= 表长
    if(!(p = GetElemP_DuL(L,i)));
        return ERROR;
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}
