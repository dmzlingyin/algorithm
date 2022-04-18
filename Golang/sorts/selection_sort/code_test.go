package selection_sort

import "testing"

func TestSort(t *testing.T) {
	nums := []int{1, 3, 0, 4, -9, 2, 3, 7, 9}
	sort(nums)
}
