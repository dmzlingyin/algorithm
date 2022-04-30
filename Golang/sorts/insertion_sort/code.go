package insertion_sort

func sort(nums []int) []int {
	for i := 0; i < len(nums); i++ {
		cur := nums[i]
		pre := i - 1
		for pre >= 0 && cur < nums[pre] {
			nums[pre+1] = nums[pre]
			pre--
		}
		nums[pre+1] = cur
	}
	return nums
}
