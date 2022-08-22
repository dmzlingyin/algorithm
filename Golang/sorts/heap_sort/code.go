package heapsort

import (
	"gol/heap"
)

// 逐个元素Insert入堆中, 再ExtractMax
// 不是真正意义的堆排序， Insert O(nlogn)
func fakeHeapSort(nums []int) []int {
	n := len(nums)
	heap := heap.NewHeap(n)
	for i := 0; i < n; i++ {
		heap.Insert(nums[i])
	}
	for j := n - 1; j >= 0; j-- {
		nums[j] = heap.ExtractMax()
	}
	return nums
}

// 初始化heap数组, 先从 n / 2 shiftdown, 再ExtractMax
// 真正的堆排序, Heapify O(n)
func heapSort(nums []int) []int {
	h := heap.Heapify(nums)
	for i := len(nums) - 1; i >= 0; i-- {
		nums[i] = h.ExtractMax()
	}
	return nums
}
