package main

import (
	"fmt"
	"strconv"
)

// func main() {
// 	var n int
// 	var s1, s2 string
// 	fmt.Scanf("%d", &n)
// 	fmt.Scan(&s1)
// 	fmt.Scan(&s2)

// 	res := make([]byte, 2*n)
// 	index := 0
// 	i, j := 0, 0
// 	for index < 2*n {
// 		if index%2 == 0 {
// 			res[index] = s1[i]
// 			i++
// 		} else {
// 			res[index] = s2[j]
// 			j++
// 		}
// 		index++
// 	}
// 	fmt.Println(string(res))
// }

// func main() {
// 	var n, m int
// 	fmt.Scanf("%d %d", &n, &m)
// 	ps := make([]int, n)
// 	scores := make([]int, n)

// 	for i := 0; i < n; i++ {
// 		var a int
// 		fmt.Scan(&a)
// 		ps[i] = a
// 	}
// 	for i := 0; i < n; i++ {
// 		var a int
// 		fmt.Scan(&a)
// 		scores[i] = a
// 	}

// 	dp := make([][]float64, n)
// 	for k, _ := range dp {
// 		dp[k] = make([]float64, m+1)
// 	}
// 	dp[0][0] = float64(scores[0]*ps[0]) * 0.01
// 	for i := 1; i < n; i++ {
// 		dp[i][0] = dp[i-1][0] + float64(scores[i]*ps[i])*0.01
// 	}
// 	for j := 1; j <= m; j++ {
// 		dp[0][j] = float64(scores[0]) * 1.0
// 	}

// 	for i := 1; i < n; i++ {
// 		// nofu := float64(ps[i]*scores[i]) * 0.01
// 		for j := 1; j <= m; j++ {
// 			if j < i {
// 				dp[i][j] = dp[i-1][j]
// 			} else {
// 				dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+float64(scores[i])*1.0)
// 			}
// 		}
// 	}
// 	fmt.Printf("%.2f", dp[n-1][m])
// }

// func max(a, b float64) float64 {
// 	if a > b {
// 		return a
// 	}
// 	return b
// }

func main() {
	var employe string
	var iyear string
	var nums int
	fmt.Scan(&employe)
	fmt.Scan(&iyear)
	fmt.Scan(&nums)

	year, _ := strconv.Atoi(iyear)
	fmt.Println(year)
	if year < 0 || year > 7 {
		fmt.Println("Error: 工龄输入错误")
		return
	}

	switch employe {
	case "s":
		pay := 2000 + year*100 + int(float64(nums)*0.001)
		fmt.Println(pay)
	case "w":
		pay := 2000 + year*200 + int(float64(nums)*0.5)
		fmt.Println(pay)
	default:
		fmt.Println("Error: 员工类型输入错误")
	}
}
