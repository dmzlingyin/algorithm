/*
Author:lingyin
Date:2019-06-08
Main content:stack
本文件中，结构体变量的访问并不是按照c语言严格执行的，在这只是一个抽象的描述。
*/

/****************************************ADT Stack的表示与实现***********************************************/


#define STACK_INIT_SIZE 100         //存储空间的初始分配量
#define STACKINCREMENT  10          //存储空间分配增量

typedef struct
{
    SElemType   *base;  //栈底指针
    SElemType   *top;   //栈顶指针
    int stacksize;      //当前分配的存储空间

}SqStack;


/******************************************基本操作函数原型声明*********************************************/

Status InitStack(SqStack &S);                       //构造一个空栈
Status DestoryStack(SqStack &S);                    //销毁一个栈
Status ClearStack(SqStack &S);                      //把S置为空栈
Status StackEmpty(SqStack &S);                      //若栈S为空，返回True，否则返回False
int StackLength(SqStack &S);                        //返回S的元素个数，即栈的长度
Status GetTop(SqStack S,SElemType &e);              //若栈不为空，则用e返回栈顶元素，并返回OK,否则返回ERROR
Status Push(SqStack &S,SElemType e);                //插入元素e为新的栈顶元素
Status Pop(SqStack &S,SElemType &e);                //若栈不为空，则删除S的栈顶元素，用e返回其值，并返回OK,否则，返回ERROR
Status StackTraverse(SqStack S,status(*visit)())    //从栈底到栈顶一次对栈中的每个元素调用函数visit().一旦visit()失败，这操作失败。

/******************************************基本操作的算法描述*********************************************/

Status InitStack(SqStack &S)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(S.base == NULL)
    {
        printf("空间分配失败！！！")；
        exit(0);
    }

    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
    //判断栈是否为空
    if(S.top == S.base)
    {
        printf("操作失败，栈为空!!");
        return ERROR;
    }
    *e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S,SElemType e)
{
    if(S.top - S.base >= S.stacksize)//栈满
    {
        S.base = (SElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!S.base)
            exit(0);
        S.top = S.base + S.stacksize;
        s.stacksize =+ STACKINCREMENT;
    }
    *S.top ++ = e;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
    if(S.top == S.base)
        return ERROR;
    e = * --S.top;
    return OK;
}


/******************************************栈的实际应用 进制的转换(顺序栈)*********************************************/

/*
十进制数N，和d进制数的转换
N = (N / d) * d + N % d
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int *base;
    int *top;
}Stack,*pStack;


Stack s={0};//结构体的声明



void InitStack()
{

    s.base = (int *)malloc(100 * sizeof(int));
    if(!s.base)
    {
        printf("内存申请失败!!");
        exit(0);
    }
    s.top = s.base;
    printf("栈初始化成功!!\n");

}

void push(pStack s,int value)
{
    //判断栈是否溢出
    if(s->base - s->top >= 100)
    {
        printf("栈已满，数据入栈失败!");
        exit(0);
    }
    *(s->top) = value;
    s->top--;
}

int pop(pStack s)
{
    int tmp = 0;
    //判断是否是空栈
    if(s->top == s->base)
    {
        printf("当前栈为空，不能出数据");
        exit(0);
    }

    s->top++;
    tmp = *(s->top);
    return tmp;

}
int StackEmpty(pStack s)
{
    if(s->base == s->top )
        return 1;
    return 0;
}
void convert(int num,int scale)
{

    while(num)
    {
        push(&s,num % scale);

        num /= scale;
    }

}

void main()
{
    int num;//要转化的十进制数
    int scale;//进制

    InitStack();
    printf("请输入要转化的十进制数:\n");
    scanf("%d",&num);
    printf("您想转化为几进制呢？\n");
    scanf("%d",&scale);
    convert(num,scale);
    while(!StackEmpty(&s))
    {
        printf("%d",pop(&s));
    }
    printf("\n");
}


/******************************************栈的实际应用 进制的转换(链栈)*********************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct stacknode
{
    int data;                   //节点数据
    struct stacknode *next;     //节点指针
}StackNode,*pStackNode;

//栈底，栈顶方向标
typedef struct stack
{
    pStackNode base;     //栈底
    pStackNode top;      //栈顶
    int stacksize;  //栈中元素的个数
}Stack,*pStack;

int num = 1314;
int scale = 2;

//初始化一个stack的实例，填充0
Stack s = {0};

//指针指向stack实例
pStack pS = &s;


//创建头指针
pStackNode StackNodeInit()
{

    pStackNode pHeadNode;
    //头结点
    pStackNode HeadNode = (pStackNode)malloc(sizeof(StackNode));
    HeadNode->data = 0;
    HeadNode->next = NULL;
    pHeadNode = HeadNode;//头指针指向第一个节点

    return pHeadNode;//返回头指针

}

//每次Push，调用一次
pStackNode CreatList(pStack s)
{


        pStackNode pNode = (pStackNode)malloc(sizeof(StackNode));
        pNode->next = s->top;
        pNode->data = 0;
        s->top = pNode;//向右移动指针
        return s->top;


}


void StackInit(pStackNode p)//接受一个参数，类型为pStackNode
{
    s.base = p;   //栈底指向节点1
    s.top = s.base;     //栈顶也指向节点1
    s.stacksize = 0;    //栈中元素个数为0
}

void push(pStack s,int value)
{

    s->top->data = value;
    s->top = CreatList(s);

}

//出栈，返回栈顶的数据
int pop(pStack s)
{


    int value;
    pStackNode p = s->top;
    if(s->base == s->top)
    {
        printf("栈为空,无数据输出!\n");
        exit(0);
    }

    s->top = s->top->next;
    value = s->top->data;
    free(p);
    return value;

}

int StackEmpty(pStack s)
{
    if(s->base == s->top)
        return 1;
    return 0;
}
void convert(pStack s,int num,int scale)
{
    while(num)
    {
        push(s,num % scale);
        num /= scale;
    }
}

void output(pStack s)
{
    while(!StackEmpty(s))
    {
        printf("%d",pop(s));

    }
    printf("\n");
}

void Init()
{
    printf("***************************************************************************\n");
    printf("*                                                                         *\n");
    printf("*                      Welcome to use number convert tool                 *\n");
    printf("*                      This tools was programed by lingyin                *\n");
    printf("*                                 Version 1.0                             *\n");
    printf("*                                                                         *\n");
    printf("*                                                                         *\n");
    printf("***************************************************************************\n");

    printf("\n");
    printf("\n");
    printf("\n");
    printf("Please input the NUM that you want to convert:");
    scanf("%d",&num);
    printf("Please input the SCALE that you want to convret:");
    scanf("%d",&scale);


}
void main()
{
    //p为头指针
    pStackNode p = StackNodeInit();

    //栈的初始化,总指挥的初始化
    StackInit(p);

    Init();
    convert(pS,num,scale);

    //最后的输出
    output(pS);



}
/******************************************栈的实际应用 括号的合法性检测************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct Stack
{
    char * base;
    char * top;
    int stacksize;

}Stack,*pStack;

//定义一个struct Satck变量
Stack s={0};

//获得s的指针
pStack pS = &s;

void StackInit(pStack ps)
{
    int *addr;
    addr = (int *)malloc(MAX * sizeof(int));
    if(!addr)
    {
        printf("内存申请失败!");
        exit(0);
    }

    ps->base = addr;
    ps->top = ps->base;


}


void main()
{

    char string[MAX]={0};
    //栈的初始化
    StackInit(pS);

}
