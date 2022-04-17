func minimumRounds(tasks []int) int {
	hash := make(map[int]int, len(tasks))
	for _, v := range tasks {
		hash[v]++
	}

	count := 0
	for k, v := range hash {
		res := []int{}
		if v%3 == 0 {
			res = append(res, v/3)
		} else {
			if v % 2 == 0 {
				res = append(res, v/2)
			}
			a := v % 3
			b := v / 3
			c := v % 2
			d := v / 2		 
			if a == 2 {
				res = append(res, 1 + b)
			}
			if c == 3 {
				res = append(res, 1 + d)
			}

			if v % 2 != 0 && a != 2 && c != 3 {
				return -1
			}
			count += min(res)
		}
	return count
}

func min(nums []int) int {
	a := math.MaxInt
	for _, v := range nums {
		if v < a {
			a = v
		}
	} 
	return a
}