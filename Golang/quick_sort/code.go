/*
快速排序最坏情况为O(n2), 平均情况为O(nlogn), 但大多数情况, 快速排序要优于复杂度稳定与O(nlogn)的归并排序.
Author: Lingyin
Date: 2022-04-06
*/

package quick_sort

func QuickSort(data []int) {
	left, right := 0, len(data)-1
	if left >= right {
		return
	}

	pivot := data[left]
	for left < right {
		for (left < right) && (data[right] > pivot) {
			right--
		}
		if left < right {
			data[left] = data[right]
			left++
		}

		for (left < right) && (data[left] < pivot) {
			left++
		}
		if left < right {
			data[right] = data[left]
			right--
		}
	}
	data[left] = pivot
	QuickSort(data[:left])
	QuickSort(data[left+1:])
}

func quickSort() []int {
	data := []int{3, 4, 5, 3, 6, 8, 9, 3, 5}
	QuickSort(data)
	return data
}
