/*
Author:Lingyin
Date:2019-04-25
二分法，查找算法
*/

#include<stdio.h>

#define N 7

int arr[N] = {8,12,23,65,145,235,652};


//查找value,并返回value的索引
int binary_search(int arr[],int value)
{

    int left = 0;//指向左半部分
    int right = N - 1;//指向右半部分
    int mid = 0;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(arr[mid] == value)
            return mid;
        if(arr[mid] > value)
            right = mid - 1;
        if(arr[mid] < value)
            left = mid + 1;
        
        
    } 
    return -1;

}
int main()
{
    int r = binary_search(arr,23);
    printf("%d",r);
    return 0;
}