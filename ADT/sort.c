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
/*
BubbleSort
It is a stable algorithm of sort.
Date:2019-10-02
complex of time:O(n*n)
*/

void BubbleSort(ElemType A[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        flag = false;//标志位，标识本次遍历是否发生交换

        for(j=n-1;j>i;j--)
        {
            if(A[j-1].key > A[j].key)
            {
                swap(A[j-1],A[j]);
                flag = true;
            }
        }

        if(flag == false)
            return;
    }
}
/************************************************************************************************/
/*SelectSort

It is a unstable algorithem of sort.
complex of time:O(n*n)
*/

void SelectSort(ElemType A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        min = i;//记录最小元素的索引
        for(int j=i+1;j<n;j++)
        {
            if(A[j].key < A[min].key)
                min = j;
        }

        if(min != i)
            swap(A[i],A[min]);
    }
}
/************************************************************************************************/
/*
heapsort
It is a unstable algorithm of sort.
complex of time:O(nlogn).

步骤：
1. 将所有的待排序序列构建一个完全二叉树
2. 将这个完全二叉树调整为大(小)顶堆
3. 输出根节点上的数字
4. 将剩余节点元素再次调整组织成一个新的小顶堆
5. 多次执行3,4操作，直到输出所有元素，排序完成。
*/

//构造初始堆
void BuildMaxHeap(ElemType A[],int len)
{
    for(i=len/2;i>0;i--)        //从下往上第一个非叶子节点开始调整，直至根节点。
        AdjustDown(A,i,len);
}

void AdjustDown(ElemType A[],int k,int len)
{
    A[0] = A[k];//暂存

    for(i=2*k;i<=len;i*=2)
    {
        if(i<len && A[i]<A[i+1])
            i++;
        if(A[0]>=A[i])
            break;
        else
        {
            A[k] = A[i];
            k = i;
        }
    }

    A[k] = A[0];
}

//依次输出节点调整堆

void HeapSort(ElemType A[],int len)
{
    BuildMaxHeap(A,len);
    for(i=len;i>1;i--)
    {
        swap(A[i],A[1]);
        AdjustDown(A,1,i-1);
    }
}

//插入操作
void AdjustUp(ElemType A[],int k)
{
    A[0] = A[k];
    i = k/2; //i指向双亲

    while(i>0&&A[i]<A[0])
    {
        A[k] = A[i];
        k = i;
        i = k/2;
    }

    A[k] = A[0];
}
/************************************************************************************************/
