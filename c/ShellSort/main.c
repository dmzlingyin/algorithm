/*
Date:2019-10-02
Author:LingYin

ShellSort is a unstable algorithm of sort.
*/

#include <stdio.h>
#include <stdlib.h>

int sort[10]={15,26,38,80,70,20,8,19,40,20};

void ShellSort(int A[],int n)
{
    int i,j,dk;
    int tmp;
    for(dk=n/2;dk>=1;dk=dk/2)
    {
        for(i=dk;i<n;i++)
        {
            if(A[i]<A[i-dk])
            {
                tmp = A[i];
                for(j=i-dk;j>=0&&tmp<A[j];j=j-dk)
                    A[j+dk] = A[j];

                A[j+dk] = tmp;
            }
        }
    }

}
int main()
{
    int i;
    printf("排序之前：\n");
    for(i=0;i<10;i++)
    {
        printf("%d \t",sort[i]);
    }
    printf("\n");
    ShellSort(sort,10);
    printf("排序之后：\n");
    for(i=0;i<10;i++)
    {
        printf("%d \t",sort[i]);
    }
    return 0;
}
