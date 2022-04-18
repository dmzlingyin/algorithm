package math

import (
	"fmt"
	"math"
)

// compute a / b
func code(a, b int) int {
	// a := 1
	// b := -1
	// c := 2
	// fmt.Println(" ^ 操作, 判断两数符号是否相异:")
	// fmt.Println((a ^ b) < 0)
	// fmt.Println((a ^ c) < 0)

	fmt.Println(" << 左移操作:")
	fmt.Println(3 << 1)
	fmt.Println(3 << 3)
	fmt.Println(1 << 32)
	count := 0
	num := b
	for num <= a {
		num = b << count
		count++
	}

	res := 0
	for i := count - 2; i >= 0; i = i - 2 {
		a = a - (b << i)
		res += a
	}
	if res > math.MaxInt32 || res < math.MinInt32 {
		return math.MaxInt32
	}
	return res
}
