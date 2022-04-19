package insertion_sort

import "fmt"

func sort(nums []int) {
	for i := 0; i < len(nums); i++ {
		cur := nums[i]
		pre := i - 1
		for pre >= 0 && cur < nums[pre] {
			nums[pre+1] = nums[pre]
			pre--
		}
		nums[pre+1] = cur
	}
	fmt.Println(nums)
}
