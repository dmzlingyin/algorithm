package shellsort

func shellsort(nums []int) []int {
	length := len(nums)
	gap := 1
	for gap < length/3 {
		gap = gap*3 + 1
	}
	for gap > 0 {
		for i := gap; i < length; i++ {
			temp := nums[i]
			j := i - gap
			for j >= 0 && nums[j] > temp {
				nums[j+gap] = nums[j]
				j -= gap
			}
			nums[j+gap] = temp
		}
		gap /= 3
	}
	return nums
}
