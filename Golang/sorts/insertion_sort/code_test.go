package insertion_sort

import "testing"

func TestSort(t *testing.T) {
	nums0 := []int{4, 3, 5, 6, 3, 1, 7, 2, 3, 4, 9}
	nums1 := []int{4, 1, 7, 2, 3, 4, 9}
	nums2 := []int{9, -1, -999}
	sort(nums0)
	sort(nums1)
	sort(nums2)
}
