/*
Date:2019-10-13
Author:Lingyin
*/

//二叉排序树的查找

BSTree *BST_Search(BiTree T,ElemType key,BSTNode *&p)
{
    p = NULL;//p指向空，避免野指针

    while(T != NULL && key != T->data)
    {
        p = T;
        if(key<T->data)
            T = T->lchild;
        else
            T = T->rchild;
    }

    return T;
}

//二叉排序树的插入

int BST_Insert(BiTree &T,KeyType k)
{
    //节点的插入是树的最末端，所以，当前节点为空，即插入位置
    if(T == NULL)
    {
        T = (BiTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = NULL;
        T->rchild = NULL;
        return 1;
    }
    else if(k == T->key)
        return 0;//不需要插入，树中已有
    else if(k < T->key)
        return BST_Insert(T->lchild,k);
    else
        return BST_Insert(T->rchild,k);

}

//二叉排序树的构造

void Create_BST(BiTree &T,keyType str[],int n)
{
    T = NULL;
    int i=0;
    while(i<n)
    {
        BST_Insert(T,str[i]);
        i++;
    }
}
