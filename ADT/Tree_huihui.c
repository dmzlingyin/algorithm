/*
Date:2019-07-28
树
*/

//双亲表示法
//双亲表示法结构体定义
#define MAXSIZE 100
typedef struct PTNode
{
    int data;
    int parent;
}PTNode;

//节点数组
typedef struct
{
    PTNode nodes[MAXSIZE];
    int r,n;//根的位置，和节点数
}PTree;

//孩子法表示节点结构体定义
#define MAXSIZE 100

//孩子节点
typedef struct CTNode
{
    int child;
    struct CTNode *next;
}*ChildPtr;

//表头结构
typedef struct
{
    int data;
    ChildPtr firstchild;
}CTbox;

typedef struct
{
    CTbox nodes[MAXSIZE];
    int r,n;
}CTree;


/*************************************************************************************************/

//孩子兄弟表示法，考研最常用类型

//结构体定义
typedef struct CSNode
{
    int data;
    struct CSNode *left,*right;
}CSNode,*CSTree;


//树的先序遍历
void PreTravelTree(BitNode * root)
{

    StackNode *s;//栈指针
    BitNode *p;//工作指针

    s = NULL;
    p = root;

    s = InitStack(s);//初始化栈
    if(p == NULL)
    {
        printf("栈为空!");
        exit(0);
    }

    while(p || !StackEmpty(s))
    {
        if(p)
        {
            push(s,p)//入栈
            printf("%d",p->data);
            p = p->lchild;
        }
        else
        {
            pop(s,p);
            p = p->rchild;
        }
    }

    free(s);

}

//递归先序遍历

void preOrder(BitNode *root)
{
    if(root)
    {
        printf("%d",root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

//树的非递归中序遍历

void InOrderTravelTree(BitNode *root)
{
    //栈指针
    StackNode *s;

    //工作指针
    BitNode *p;

    s = NULL;
    p = root;
    s = InitStack(s);//初始化栈

    //if the tree is empty,return something.

    while(p || !StackEmpty(s))
    {
        if(p)
        {
            push(s.p);
            p = p->lchild;
        }
        else
        {
            pop(s.p);
            printf("%d",p->data);
            p = p->rchild;
        }
    }

    free(s);

}



