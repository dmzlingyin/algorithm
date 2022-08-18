package misc

import "fmt"

func ch() {
	ch := make(chan int, 2)
	fmt.Println(ch)

	a := []int{}
	a = append(a, 1, 2, 3, 4, 5)
	fmt.Println(cap(a))
}
