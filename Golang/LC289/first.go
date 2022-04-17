func digitSum(s string, k int) string {
	a := s
	for len(a) > k {
		res := [][]byte{}
		str := []byte(a)
		answer := []int{}
		count := 0

		for i := 0; i+k < len(str); i = i + k {
			count++
			res = append(res, str[i:i+k])
		}
		res = append(res, str[count*k:])
		for _, v := range res {
			subSum := sum(v)
			answer = append(answer, subSum)
		}
		a = compose(answer)
	}
	return a
}

func sum(nums []byte) int {
	sum := 0
	for _, v := range nums {
		sum += int(v) - 48
	}
	return sum
}

func compose(nums []int) string {
	a := ""
	for _, v := range nums {
		a += strconv.Itoa(v)
	}
	return a
}
