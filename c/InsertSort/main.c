/*
Author:Lingyin
Date:2019-09-19
*/
#include <stdio.h>
#include <stdlib.h>

int sort[15]={1,6,25,32,4,12,26,35,21,2,3,89,74,5,6};

int tmp;
void InsertSort(int sort[],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        if(sort[i] < sort[i-1])
        {
            tmp = sort[i];
            for(j=i-1;tmp<sort[j];j--)
                sort[j+1] = sort[j];
            sort[j+1] = tmp;
        }

    }
}

int main()
{
    int i;
    InsertSort(sort,15);
    for(i=0;i<15;i++)
        printf("%d \t",sort[i]);
    return 0;
}
