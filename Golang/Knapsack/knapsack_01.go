package knapsack

import "fmt"

func knapsack01(weight, value []int, bagweight int) {
	dp := make([][]int, len(weight))
	for k := range dp {
		dp[k] = make([]int, bagweight+1)
	}
	// dp初始化
	for j := weight[0]; j <= bagweight; j++ {
		dp[0][j] = value[0]
	}

	for i := 1; i < len(weight); i++ {
		for j := 0; j <= bagweight; j++ {
			if j < weight[i] {
				dp[i][j] = dp[i-1][j]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i])
			}
		}
	}
	fmt.Printf("the max value is: %d\n", dp[len(weight)-1][bagweight])
}

func knapsack(weight, value []int, bagweight int) {
	dp := make([]int, bagweight+1)
	for i := 0; i < len(weight); i++ {
		for j := bagweight; j >= weight[i]; j-- {
			dp[j] = max(dp[j], dp[j-weight[i]]+value[i])
		}
	}
	fmt.Printf("the max value is: %d\n", dp[bagweight])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
