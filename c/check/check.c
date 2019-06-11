#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    char *addr;
    addr = (char *)malloc(MAX * sizeof(char));
    if(!addr)
    {
        printf("内存申请失败!");
        exit(0);
    }

    ps->base = addr;
    ps->top = ps->base;


}

void push(pStack ps,char ch)
{	
	*(ps->top) = ch;
	(ps->top)--;
}

void pop(pStack ps)
{
	(ps->top)++; 
}

char gettop(pStack ps)
{
	char * tmp = ps->top;
	tmp ++;
	return *tmp;
}

char reverse(char c)
{
	if(c == '(')
		return ')';
	if(c == '{')
		return '}';
	if(c == '[')
		return ']';
	else
		return 0;
}
void check(char *str,int length,pStack ps)
{
	int i;
	for(i = 0;i < length;i++)
	{
		if( str[i] == '(' || str[i] == '{' || str[i] == '[')	
			push(ps,str[i]);
		if(str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if(reverse(gettop(ps)) == str[i])
				pop(ps);
			else
			{
				printf("括号不合法!\n");
				exit(0);
			}
		}
	}

	printf("您输入的字符串没有问题!\n");
}
void main()
{
	int length;
    char string[MAX]={0};
    //栈的初始化
    StackInit(pS);
    printf("Please input the string you want to check:");
    scanf("%s",string);
    length = strlen(string);
	check(string,length,pS);
	printf("\n");
}