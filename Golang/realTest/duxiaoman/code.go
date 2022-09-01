// package main

// import (
// 	"fmt"
// 	"sort"
// )

// func main() {
// 	var n, k int
// 	fmt.Scan(&n)
// 	fmt.Scan(&k)

// 	arr := make([]int, n)
// 	for i := 0; i < n; i++ {
// 		var a int
// 		fmt.Scan(&a)
// 		arr[i] = a
// 	}

// 	res := [][]int{}
// 	for i := 0; i < n; i++ {
// 		var tmp []int
// 		for j := i; j < n; j++ {
// 			tmp = arr[i : j+1]
// 			res = append(res, tmp)
// 		}
// 	}
// 	fmt.Println(getGood(res, k))
// }

// func getGood(arr [][]int, k int) int {
// 	res := 0
// 	for i := 0; i < len(arr); i++ {
// 		tmp := make([]int, len(arr[i]))
// 		copy(tmp, arr[i])
// 		sort.Ints(tmp)
// 		if (tmp[0] * k) == tmp[len(tmp)-1] {
// 			res++
// 		}
// 	}
// 	return res
// }

package main

import "fmt"

func main() {
	var T, n, m, k, x int
	fmt.Scan(&T)

	for i := 0; i < T; i++ {
		// processing every single data
		fmt.Scan(&n)
		fmt.Scan(&m)
		fmt.Scan(&k)
		fmt.Scan(&x)

		// init arr
		arr := make([][]int, n)
		for i := range arr {
			arr[i] = make([]int, m)
		}
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				var a int
				fmt.Scan(&a)
				arr[i][j] = a
			}
		}

		res := false
		// core code
		track(arr, n, m, x, 0, 0, 0, &res)
		if res {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

func track(arr [][]int, n, m, x int, startx, starty int, sum int, res *bool) {
	if (startx == n-1) && (starty == m-1) {
		v := sum + arr[startx][starty]
		if v == x {
			*res = true
		}
		return
	}
	if startx >= n || starty >= m {
		return
	}
	tmp := sum
	for i := startx; i < n; i++ {
		for j := starty; j < m; j++ {
			sum += arr[i][j]
			track(arr, n, m, x, i+1, j, sum, res)
		}
		sum = tmp
	}
}
