package selection_sort

import "testing"

func TestSort(t *testing.T) {
	nums := []int{1, 3, 2, 4, 5, 2, 3, 7, 9}
	sort(nums)
}
