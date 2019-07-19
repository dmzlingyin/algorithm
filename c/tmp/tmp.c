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
	


	//链表a用来存放交集的值
	La->next = NULL;


	for(pa != NULL;pa = pa->next)
	{
		for(pb != NULL;pb = pb->next)
		{
			if(pa->data == pb->data)
			{
				
				t = (LNode)malloc(sizeof(Node));
				t->next = La->next;
				t->data = pa->data;
				La->next = t;
				
				
			}
		}
	}

}

void main()
{
	LNode La = InitList();
	LNode Lb = InitList();

	CreateList(La,Lb);


	Find_inter(La,Lb);


	while(La->next)
	{
		printf("%d\n",La->next->data);
		La = La->next;
	}
	
}
