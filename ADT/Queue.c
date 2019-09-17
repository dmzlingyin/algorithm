/*
Author:Lingyin
Date:2019-06-07
ADT Queue describtion & complete
*/

//队列的链式存储结构
typedef struct QNode{
    QElemType       data;
    struct QNode    *next;
}QNode,*QueuePtr;

//Controller
typedef struct{
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾指针
}LinkQueue;

/*********************************************基本操作的函数原型说明********************************/

//构造一个空的队列
Status InitQueue(LinkQueue &Q)

//销毁一个队列
Status DestroyQueue(LinkQueue &Q)

//清空队列
Status ClearQueue(LinkQueue &Q)

//判断队列是否为空，是返回TRUE，
Status QueueEmpty(LinkQueue &Q)

//返回队列的元素个数
int QueueLength(LinkQueue &Q)

//若队列不为空，则使用e返回队列的队头元素，并返回OK
Status GetHead(LinkQueue Q,QElemType &e)

//插入元素e为Q的新的队尾元素
Status EnQueue(LinkQueue *Q,QElemType e)

//若队列不为空，则删除队列的队头元素，用e返回其值，并返回OK
Status DeQueue(LinkQueue &Q,QElemType &e)

//从队头到队尾一次对队列Q中的每个元素调用函数visit(),一旦visit失败，则操作失败
Status QueueTraverse(LinkQueue &Q,visit())


/********************************************基本操作的算法描述********************************/

//构造一个空的队列
Status InitQueue(LinkQueue &Q)
{
    Q->front = Q.rear = (QueuePtr)malloc(sizeof(QNode));//申请的为头结点
    if(!Q->front)
        exit(OVERFLOW)//分配空间失败
    Q.front->next = NULL;
    return OK;
}


//从头结点开始，依次向后free.
Status DestroyQueue(LinkQueue &Q)
{
    while(Q->front)
    {
        Q->real = Q->front->next;
        free(Q->front);
        Q->front = Q->real;
    }
    return OK;
}

//插入新的队尾元素
Status EnQueue(LinkQueue &Q,QElemType e)
{
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q->real->next = p;
    Q->real = p;
    return OK;
}

//删除队头元素
Status DeQueue(LinkQueue &Q,QElemType &e)
{
    //判断是否为空
    if(Q->real == Q->front)
        return ERROR;
    p = Q->front->next;
    e = p->data;
    Q->front->next = p->next;
    if(Q->real == p)
        Q->real = Q->front;
    free(p);
    return OK;
}


/*******************************************循环队列********************************/
//队列的顺序存储结构

//最大队列长度
#define MAXQSIZE 100

typedef struct{
    QElemType *base;    //初始化的动态分配存储空间
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue &Q)
{
    Q->base = (QElemType)malloc(MAXQSIZE * sizeof(QElemType));
    if(!Q->base)
        exit(OVERFLOW);
    Q->front = Q->rear = 0;
    return OK;
}

//返回队列的元素个数
int QueueLength(SqQueue Q)
{
    return (Q.real - Q.front + MAXQSIZE) % MAXQSIZE;
}

//插入元素e
Status EnQueue(SqQueue &Q,QElemType e)
{
    if((Q->rear + 1) % MAXQSIZE == Q->front)
        return ERROR;//队列已满
    Q->base[Q->rear] = e;
    Q->real = (Q->rear + 1) % MAXQSIZE;
    return OK;
}

//删除队头元素,用e返回其值
Status DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q->rear == Q->front)
        return ERROR;//队列为空
    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}

