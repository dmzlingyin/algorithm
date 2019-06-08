#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int *base;
    int *top;
}Stack,*pStack;

/*
void convert(int num);
int StackEmpty(pStack s);
int pop(pStack s);
void push(pStack s,int value);
*/
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