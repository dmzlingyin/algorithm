/******************************************************************************************/
/*
直接插入排序
空间复杂度O(1)
最好时间复杂度O(n)
最坏时间复杂度O(n*n)
平均时间复杂度O(n*n)
为稳定性算法
*/

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


void InsertSort(ElemType sort[],int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        if(sort[i]<sort[i-1])
        {
            sort[0] = sort[i];
            for(j=i-1;sort[0]<sort[j];j--)
                sort[j+1] = sort[j];
            sort[j+1] = sort[0];
        }
    }
}

/************************************************************************************************/
//折半插入排序

//折半插入排序是在直接插入排序的基础上，增加了二分查找的思想，从而减少了比较的次数。
//平均时间复杂度为O(n*n),是稳定性排序算法
void BinaryInsertSort(ElemType A[],int n)
{
    int i,j;
    int low,high,mid;

    //从第二个元素开始进行遍历
    for(i=2;i<=n;i++)
    {

        if(A[i].key<a[i-1].key)
        {
            low = 1;
            high = i-1;
            A[0] = A[i];

            while(low<=high)
            {
                mid = (low + high) / 2;
                if(A[mid].key>A[0].key)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            for(j=i-1;j>=high+1;j--)
                A[j+1] = A[j];
            A[high+1] = A[0];

        }
    }
}




/************************************************************************************************/

/*希尔排序

不是稳定的排序算法
最坏的时间复杂度为O(n*2)
平均为O(n*1.3)

*/

void ShellSort(ElemType A[], int n)
{
    int i,j,dk;
    for(dk=n/2;dk>=1;dk=dk/2)
    {
        for(i=dk+1;i<=n;i++)
        {
            if(A[i].key<A[i-dk].key)
            {
                A[0] = A[i];
                for(j=i-dk;j>0&&A[0].key<A[j].key;j=j-dk)
                    A[j+dk] = A[j];
                A[j+dk] = A[0];
            }
        }
    }
}
/************************************************************************************************/
/************************************************************************************************/
