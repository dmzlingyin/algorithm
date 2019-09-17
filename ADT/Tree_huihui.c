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


//递归中序遍历
void inOrder(BiTNode *root)
{
    if(root)
    {
        inOrder(root->lchild);
        printf("%d",root->data);
        inOrder(root->rchild);
    }
}


//树的非递归后序遍历

void LastTravelTree(BiTNode *root)
{
    StackNode s;
    BiTNode *cur,*pre;//一个当前节点指针，一个指向上一个访问的节点

    if(root == NULL)
    {
        printf("树为空");
        exit(0);
    }

    pre = NULL;
    cur = NULL;
    s = InitStack(s);

    push(s,root);//根节点入栈

    while(!StackEmpty(s))
    {
        cur = NULL;
        GetTop(s,cur);

        if((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == (cur->lchild || cur->rchild))))
        {
            printf("%d",cur->data);
            pre = cur;
            pop(s,cur);
        }

        else
        {
            if(cur->rchild != NULL)
                push(s,cur->rchild);
            if(cur->lchild != NULL)
                push(s,cur->lchild);

        }


    }


    free(s);

}

//后序遍历递归代码

void postOrder(BiTNode *root)
{
    if(root)
    {
        postOrder(root->lchild);
        postOrder(root->rhild);
        printf("%d",root->data);
    }
}


//层次遍历，自上而下，从左至右
/*
遍历的算法思想

二叉树的祖先先入栈

之后，循环执行如下操作，直到队列为空：
1. 节点出队列，执行相应操作
2. 该节点如果存在左孩子，左孩子入栈
3. 该节点如果存在右孩子，右孩子入栈

*/


void LayerOrder(BiTNode *root)
{
    LQueue Q;
    Init_Queue(Q);

    BiTNode *p;
    enQueue(Q,root);
    while(!QueueEmpty(Q))
    {
        p = deQueue(Q);
        printf("%d",p->data);
        if(p->lchild != NULL)
            enQueue(Q,p->lchild);
        if(p->rchild != NULL)
            enQueue(Q,p->rchild);
    }
}


//对二叉树践行前序线索化

void PreOrderThreat(BiThrTree BT)
{


    //前驱
    BiThrTree pre = NULL;
    if(BT != NULL)
    {
        if(BT->lchild == NULL)
        {
            BT->ltag = 1;
            BT->lchild = pre;

        }

        if(pre != NULL && pre->rtag == 1)
            pre->rchild = BT;

        if(BT->rchild == NULL)
            BT->rtag = 1;
        pre = BT;


        if(BT->ltag  == 0)
        {
            PreOrderThreat(BT->lchild);
        }
        PreOrderThreat(BT->rchild);
    }
}

//二叉树的中序线索化

void InOrderThreat(BiThrTree T)
{
    BiThrTree pre = NULL;
    if(T)
    {
        InOrderThreat(T->lchild);
        if(T->lchild == NULL)
        {
            T->rtag = 1;
            T->lchild = pre;
        }

        if(pre ！= NULL && pre->rtag == 1)
            pre->lchild = T;

        if(T->rchild == NULL)
            T->rtag = 1;
        pre = T;

        InOrderThreat(T->rchild);
    }
}

//前序 线索二叉树，求p节点的后继节点
BiThrTree PreorderNext(BiThrTree p)
{
    if(p->ltag == 0)
        return p->lchild;
    else
        return p->rchild;
}

//后序线索二叉树 求p的前驱节点

BiThrTree  PostorderPre(BiThrTree p)
{
    if(p->rtag == 0)
        return p->rchild;
    else
        return p->lchild;
}

//中序线索二叉树 p节点的前驱

BiThrTree InPre(BiThrTree p)
{
    if(p->ltag == 1)
        q = p->lchild;
    else
    {
        q = p->lchild;
        while(q->rtag == 0)
            q = q->rchild;

    }

    return q;
}
