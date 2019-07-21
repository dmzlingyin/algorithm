/*
Date:2019-07-20
灰灰考研-数据结构
*/

(Q.real + 1) % MaxSize;
(Q.front + 1) % MaxSize;
(Q.real - Q.front + MaxSize) % MaxSize;

//顺序栈的；类型描述
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

//初始化
void InitStack(SqStack &stack)
{
    stack.top = -1;
}

//判断栈空操作
int StackEmpty(SqStack stack)
{
    if(stack.top == -1)
        return TRUE;
    else
        return FALSE;
}

//进栈操作
int Push(SqStack &stack,ElemType e)
{
    //判断栈满
    if(stack.top == MaxSize - 1)
        return FALSE;
    stack.data[++top] = e;
    return TRUE;
}

//出栈操作
int Pop(SqStack &stack,ElemType *e)
{
    //判断空
    if(stack.top == -1)
        return FALSE;
    e = stack.data[top--];
    return TRUE;
}

//读取栈顶元素
int GetTop(SqStack stack,ElemType &e)
{
    if(stack.top == -1)
        return FALSE;
    e = stack.data[top];
    return TRUE;
}

//共享栈的判断操作,了解？I don't know.

//0号栈判空 top == -1
//1号栈判空 top == maxsize
//栈满 top1 - top0 == 1


//栈的链式存储

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;


/********************************************************/
//顺序队的类型描述
typedef stauct
{
    ElemType data[maxsize];
    int front,rear;
}SqQueue;

//线性队列有缺点，因此使用循环队列
/*
循环队列的判空方法：
1.牺牲一个位置
2.增加一个size变量
3.增加一个tag标志，判断最后一次的操作是插入还是删除。
*/

//方法一
//初始化
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

//判队空
int QueueEmpty(SqQueue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//入队
int EnQueue(SqQueue &Q,ElemType e)
{
    //判满
    if((Q.rear + 1) % maxsize == Q.front)
        return FALSE;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return TRUE;
}

//出队
int DeQueue(SqQueue &stack,ElemType &e)
{
    if(Q.front == Q.rear)
        return FALSE;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return TRUE;
}

/************************************************************/
//队列的链式存储

//节点结构
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

//管理结构
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//链队的初始化
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QNode)malloc(sizeof(QNode));
    Q.front->next = NULL;
}

//判队空
int QueueEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

//入队
int EnQueue(LinkQueue &Q,ElemType e)
{
    LinkQueue *q = (QNode)malloc(sizeof(QNode));
    q->next = NULL;
    q->data = e;
    Q.rear->next = s;
    Q.rear = s;
    return TRUE;
}

//出队
int DeQueue(LinkQueue &Q,ElemType &e)
{
    if(Q.front == Q.rear)
        return FALSE;
    q = Q.front->next;
    e = q->data;
    Q.front->next = q->next;
    if(q == Q.rear)
        Q.rear = Q.front;
    free(q);
    return TRUE;
}



