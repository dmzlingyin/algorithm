#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*LNode;

LNode InitList()
{
	LNode L = (LNode)malloc(sizeof(Node));
	if(!L)
		return 0;
	L->next = NULL;
	return L;
}

void CreateList(LNode L)
{
	int i;
	LNode s;
	LNode p = L;
	for(i = 0;i < 20;i++)
	{
		s = (LNode)malloc(sizeof(Node));
		s->data = i;
		s->next = NULL;
		p->next = s;
		p = s;

	}
}

void reverse(LNode L)
{
	LNode p = L->next;//指向第一个节点
	LNode t;
	L->next = NULL;
	
	while(p)
	{	
		t = p->next;
		p->next = L->next;
		L->next = p;
		p = t;
	}
}
void main()
{
	LNode L = InitList();
	CreateList(L);
	reverse(L);
	
	while(L->next)
	{
		printf("%d\t",L->next->data);
		L = L->next;
	}
	printf("\n");
}