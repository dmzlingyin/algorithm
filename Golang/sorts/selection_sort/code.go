package selection_sort

import "fmt"

func sort(nums []int) {
	for i := 0; i < len(nums); i++ {
		min := nums[i]
		index := i
		for j := i + 1; i < len(nums); j++ {
			if nums[j] < min {
				min = nums[j]
				index = j
			}
		}
		if min < nums[i] {
			nums[i], nums[index] = nums[index], nums[i]
		}
	}
	fmt.Println(nums)
}
