package lc289

func minimumRounds(tasks []int) int {
	hash := make(map[int]int, len(tasks))
	count := 0
	for _, v := range tasks {
		hash[v]++
	}

	for _, v := range hash {
		res := v % 3
		if res == 0 {
			count += v / 3
		} else if res == 1 {
			count += (v - 4) / 3
			count += 2
		} else if res == 2 {
			count += (count - 2) / 3
			count += 1
		}
	}
	return count
}
