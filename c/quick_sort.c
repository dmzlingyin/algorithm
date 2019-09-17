#include<stdio.h>

#define N 5

//Author:Lingyin
//Date:2019-04-23
int arr[N] = {23,65,156,545,32};

void quick_sort(int arr[],int low,int high)
{
    //base value
    int pivot = arr[low];
    int i = low;
    int j = high;
    if(i > j)
       return;
    
    while(i < j)
    {
        while((i < j) && (arr[j] >= pivot))
            j--;
        if(i < j)
            arr[i] = arr[j];
        while((i < j) && (arr[i] <= pivot))
            i++;
        if(i < j)
            arr[j] = arr[i];
    }

    arr[i] = pivot;
    quick_sort(arr,low,i-1);
    quick_sort(arr,j+1,high);

}

void main()
{
    int i;
    quick_sort(arr,0,4);
    for(i = 0;i < 5;i++)
    {
        printf("%d \n",arr[i]);
    }
}