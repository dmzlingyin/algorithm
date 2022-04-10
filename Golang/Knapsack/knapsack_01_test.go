package knapsack

import "testing"

func TestKnapsack(t *testing.T) {
	weight := []int{1, 3, 4}
	value := []int{15, 20, 30}
	bagweight := 4
	knapsack01(weight, value, bagweight)
}
