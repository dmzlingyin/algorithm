#! /usr/bin/python
#! -*- coding:utf-8 -*-

#Author:Lingyin
#Date:2019-04-23

'''
快速排序是devide & conquer方法的一个典型的应用
时间复杂度是O(nlogn)
'''
sort = [1,2,45,65,87,3,12,54,124,354,34,154,45]

def quick_sort(list):

    #递归退出条件，很重要
    if len(list) < 2:
        return list

    else:
        pivot = list[0] #基准值
        
        #比基准值小的值放在左边
        less = [i for i in list[1:] if i <= pivot]
        
        #比基准值大的值放在右边
        greater = [j for j in list[1:] if j > pivot]

        #递归
        return quick_sort(less) + [pivot] + quick_sort(greater)


print(quick_sort(sort))
