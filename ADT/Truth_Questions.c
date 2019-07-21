/*
Start date:2018-07-18
*/

/*
1.将两个递增的单链表合并成一个递减单链表
2019-07-18
*/
void MergeList(LinkList *La,LinkList *Lb)
{
    //分别是两个表的工作指针
    LinkList *pa = La->next,*pb = Lb->next;
    LinkList *t;//交换变量

    La->next = NULL;//La作为结果链表

    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            t = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = t;

        }
        else
        {
            t = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = t;
        }
    }

    if(pa)
        pb = pa;
    while(pb)
    {
        t = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = t;
    }
    free(Lb);

}

/*
2.有两个有序的链表，如何以最优的方式找出二者的交集，并且把它存在第一个链表中。
2019-07-18
*/

LinkList *Find_inter(LinkList *La,LinkList *Lb)
{
    //两个链表的工作指针
    LinkList *pa = La->next,*pb = Lb->next;

    //交换变量
    LinkList *t;

    //La作为存储链表
    La->next = NULL;
    for(pa;pa != NULL;pa = pa->next)
    {
        for(pb;pb != NULL;pb = pb->next)
        {
            if(pa->data == pb->data)
            {
                t = pa;
                pa->next = La->next;
                La->next = pa;
                pa = t;
            }
        }
    }
    return La;

}
