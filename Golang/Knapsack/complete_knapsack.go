package knapsack

import "fmt"

func completeKnapsack1(weight, value []int, bagweight int) {
	dp := make([]int, bagweight+1)
	for i := 0; i < len(weight); i++ {
		for j := weight[i]; j <= bagweight; j++ {
			dp[j] = max(dp[j], dp[j-weight[i]]+value[i])
		}
	}
	fmt.Println("the max value is", dp[bagweight])
}

func completeKnapsack2(weight, value []int, bagweight int) {
	dp := make([][]int, len(weight))
	for k := range dp {
		dp[k] = make([]int, bagweight+1)
		dp[k][0] = 0
	}
	for j := 0; j <= bagweight; j++ {
		dp[0][j] = (j / weight[0]) * value[0]
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
	fmt.Println("the max value is", dp[len(weight)-1][bagweight])
}
