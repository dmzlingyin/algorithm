#! /usr/bin/python
#! -*- coding:utf-8 -*-
'''
Author:Lingyin
Date:2019-04-23
二分查找
'''

arr = [1,2,5,9,23,56,89]

def binary_search(List,value):
    left = 0
    right = len(List)

    while left < right:
        mid = (left + right) // 2

        if arr[mid] == value:
            return mid
        elif arr[mid] < value:
            left = mid+1
        else:
            right = mid-1

print(binary_search(arr,25))
