//直接插入排序

void InsertSort(ElemType A[],int n)
{
    int i,j;
    for(i = 2;i <= n;i++)
    {
        if(A[i].key < A[i-1].key)
        {
            A[0] = A[i];
            for(j = i-1;A[0].key < A[j].key;j--)
                A[j+1] = A[j];
            A[j+1] = A[0];
        }
    }
}


void InsertSort(ElemType A[],int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(A[i].key < A[i-1].key;)
        {
            A[0] = A[i];
            for(j=i-1;A[0].key<A[j].key;j--)
                A[j+1] = A[j];
            A[j+1] = A[0];
        }
    }
}
