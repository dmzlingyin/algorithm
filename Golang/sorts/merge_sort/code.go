package mergesort

func mergeSort(arr []int) []int {
	length := len(arr)
	if length < 2 {
		return arr
	}
	mid := length / 2
	left := arr[:mid]
	right := arr[mid:]
	return merge(mergeSort(left), mergeSort(right))
}

func merge(left, right []int) []int {
	res := []int{}
	for len(left) != 0 && len(right) != 0 {
		if left[0] <= right[0] {
			res = append(res, left[0])
			left = left[1:]
		} else {
			res = append(res, right[0])
			right = right[1:]
		}
	}

	if len(left) != 0 {
		res = append(res, left...)
	}
	if len(right) != 0 {
		res = append(res, right...)
	}
	return res
}
