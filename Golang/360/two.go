package t360

import (
	"fmt"
	"sort"
)

func code2() {
	var N, M int
	_, _ = fmt.Scanf("%d %d", &N, &M)
	nums := make([]int, N)
	for i := 0; i < N; i++ {
		a := 0
		_, _ = fmt.Scan(&a)
		nums[i] = a
	}
	for j := 0; j < M; j++ {
		var flag, index int
		_, _ = fmt.Scanf("%d %d", &flag, &index)
		temp := nums[:index]
		if flag == 0 {
			sort.Ints(temp)
		} else {
			sort.Slice(temp, func(i, j int) bool { return temp[i] > temp[j] })
		}
	}
	for k, v := range nums {
		if k != len(nums)-1 {
			fmt.Printf("%d ", v)
		} else {
			fmt.Printf("%d", v)
		}
	}
}
