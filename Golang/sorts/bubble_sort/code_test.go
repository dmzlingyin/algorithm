package bubble_sort

import (
	"testing"
)

func TestBubble(t *testing.T) {
	nums := []int{2, 3, 7, 1, 2, 73, 0, 5}
	bubbleSort(nums)
}
