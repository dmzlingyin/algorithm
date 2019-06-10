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