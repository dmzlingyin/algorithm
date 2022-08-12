package knapsack

import "testing"

func TestKnapsack01(t *testing.T) {
	weight := []int{1, 3, 4}
	value := []int{15, 20, 30}
	bagweight := 4
	knapsack01(weight, value, bagweight)
}

func TestKnapsack(t *testing.T) {
	weight := []int{1, 3, 4}
	value := []int{15, 20, 30}
	bagweight := 4
	knapsack(weight, value, bagweight)
}

func TestCompleteKnapsack1(t *testing.T) {
	weight := []int{1, 3, 4}
	value := []int{15, 20, 30}
	bagweight := 4
	completeKnapsack1(weight, value, bagweight)
}

func TestCompleteKnapsack2(t *testing.T) {
	weight := []int{1, 3, 4}
	value := []int{15, 20, 30}
	bagweight := 4
	completeKnapsack2(weight, value, bagweight)
}
