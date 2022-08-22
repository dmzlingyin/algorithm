package t360

import "fmt"

func code1() {
	var n, m int
	_, _ = fmt.Scan(&n, &m)
	res := make([][]int, n)
	for k, _ := range res {
		res[k] = make([]int, m)
	}
	// 霸榜天数
	for i := 0; i < n; i++ {
		// 粉丝数量
		for j := 0; j < m; j++ {
			a := 0
			_, _ = fmt.Scan(&a)
			res[i][j] = a
		}
	}
	sum := 0
	for _, v := range res {
		sum += max(v)
		fmt.Printf("%d", max(v))
	}
	num := (n / 7) + (n % 7)
	sum += num
	fmt.Println(sum)
}

func max(nums []int) int {
	max := -1
	for _, v := range nums {
		if v > max {
			max = v
		}
	}
	return max
}
