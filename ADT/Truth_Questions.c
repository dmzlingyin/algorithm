/*
Start date:2018-07-18
*/

/*
1.将两个递增的单链表合并成一个递减单链表
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
