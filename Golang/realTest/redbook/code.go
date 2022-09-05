package main

import (
	"fmt"
	"math"
)

// import (
// 	"fmt"
// )

// func main() {
// 	var n, m, k int
// 	fmt.Scan(&n)
// 	fmt.Scan(&m)
// 	fmt.Scan(&k)

// 	seq := make([]int, n)
// 	for i := 0; i < n; i++ {
// 		var a int
// 		fmt.Scan(&a)
// 		seq[i] = a
// 	}

// 	seq = append(seq, seq...)
// 	reverse(seq, n*2, len(seq)-1)

// 	fmt.Println(seq[k%(n*2)])
// }

// func reverse(seq []int, i, j int) {
// 	for i < j {
// 		seq[i], seq[j] = seq[j], seq[i]
// 		i++
// 		j--
// 	}
// }

func main() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		a := new(int)
		fmt.Scan(a)
		nums[i] = *a
	}

	// code
	// 找最接近7的
	res := 0
	gap1 := math.MaxInt64
	gap2 := math.MaxInt64
	near7 := 0
	near1 := 0
	for k, v := range nums {
		if (abs(v) - 7) < gap1 {
			gap1 = abs(v) - 7
			near7 = k
		}
		if (abs(v) - 1) < grp2 {
			gap2 = abs(v) - 1
			near1 = k
		}
	}

	//找跟1最接近的
}

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}
