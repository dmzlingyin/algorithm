#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node,*LNode;

LNode InitList()
{
    //创建头结点
    LNode L = (LNode)malloc(sizeof(Node));
    L->next = NULL;
    return L;

}

void CreateList(LNode L)
{

    int i;
    LNode s,p = L;
    for(i = 0;i < 30;i++)
    {
        s = (LNode)malloc(sizeof(Node));
        s->data = rand() % 10;
        s->next = NULL;
        p->next = s;
        p = s;
    }
}

void Convert(LNode L,LNode Odd)
{
    //p指向首元结点
    LNode p = L->next;
    LNode q;


    while(p)
    {

        q = p->next;
        //奇数
        if((p->data % 2) != 0)
        {
            L->next = p->next;

            Odd->next = p;
            Odd = p;
            p->next = NULL;
            p = q;

        }
        else{
            L = p;
            p = q;
        }

    }



}
int main()
{
    LNode L = InitList();
    LNode Odd = InitList();
    LNode s = L;

    CreateList(L);
    printf("转化之前:\n");
    while(s->next)
    {
        printf("%d\n",s->next->data);
        s = s->next;
    }

    Convert(L,Odd);

    printf("偶数:\n");

    while(L->next)
    {
        printf("%d\n",L->next->data);
        L = L->next;
    }


    printf("奇数:\n");
     while(Odd->next)
    {
        printf("%d\n",Odd->next->data);
        Odd = Odd->next;
    }
    return 0;
}
