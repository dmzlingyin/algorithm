package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	arr := make([]int, n)
	for i := 0; i < n; i++ {
		a := new(int)
		fmt.Scan(a)
		arr[i] = *a
	}
	var left, right int
	fmt.Scan(&left)
	fmt.Scan(&right)

	left--
	right--
	// core code
	for left <= right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
	for _, v := range arr {
		fmt.Printf("%d", v)
	}
}
