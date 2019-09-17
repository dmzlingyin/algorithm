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

void CreateList(LNode La,LNode Lb)
{

	LNode L1 = La,L2 = Lb;
	int i,j;
	LNode s;
	
	for(i = 0;i < 34;i++)
	{	
		s = (LNode)malloc(sizeof(Node));
		s->data = i;
		s->next = NULL;
		L1->next = s;
		L1 = s;

	}

	for(j = 15;j < 40;j++)
	{	
		s = (LNode)malloc(sizeof(Node));
		s->data = j;
		s->next = NULL;
		L2->next = s;
		L2 = s;

	}
}

void Find_inter(LNode La,LNode Lb)
{
	LNode pa = La->next,pb = Lb->next;

	//交换变量
	LNode t;
	
	LNode p1;
	LNode p2;

	//链表a用来存放交集的值
	La->next = NULL;


	for(p1 = pa;p1 != NULL;p1 = p1->next)
	{
		for(p2 = pb;p2 != NULL;p2 = p2->next)
		{
			if(p1->data == p2->data)
			{
				
				
				t = (LNode)malloc(sizeof(Node));
				t->data = p1->data;
				t->next = NULL;
				La->next = t;
				La = t;
				
			}
		}
	}

	//return La;
}

void main()
{
	LNode La = InitList();
	LNode Lb = InitList();
//	LNode L = NULL;

	CreateList(La,Lb);
//	L = Find_inter(La,Lb);

	Find_inter(La,Lb);


	while(La->next)
	{
		printf("%d\n",La->next->data);
		La = La->next;
	}
	
}
