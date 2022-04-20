package selection_sort

func sort(nums []int) []int {
	for i := 0; i < len(nums); i++ {
		min := nums[i]
		index := i
		for j := i + 1; j < len(nums); j++ {
			if nums[j] < min {
				min = nums[j]
				index = j
			}
		}
		if min < nums[i] {
			nums[i], nums[index] = nums[index], nums[i]
		}
	}
	return nums
}
