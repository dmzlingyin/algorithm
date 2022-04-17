package bubble_sort

import "fmt"

func bubbleSort(nums []int) {
	for i := 0; i < len(nums); i++ {
		for j := 0; j < len(nums)-i-1; j++ {
			if nums[i] < nums[j] {
				nums[i], nums[j] = nums[j], nums[i]
			}
		}
	}
	fmt.Println(nums)
}
