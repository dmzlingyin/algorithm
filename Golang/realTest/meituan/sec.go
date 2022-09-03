package main

import (
	"fmt"
	"strconv"
)

// func main() {
// 	var a, b int
// 	fmt.Scan(&a)
// 	fmt.Scan(&b)

// 	var v int

// 	if b < 10 {
// 		v = 11 - a
// 	} else {
// 		v = b + 2 - a
// 	}
// 	fmt.Println(v)
// }

// 使用额外空间，构造一棵树

// type Node struct {
// 	val   byte
// 	left  *Node
// 	right *Node
// }

// func main() {
// 	var n int
// 	fmt.Scan(&n)

// 	vals := make([]int, n-1)
// 	for i := 0; i < n-1; i++ {
// 		var a int
// 		fmt.Scan(&a)
// 		vals[i] = a
// 	}

// 	var mark string
// 	fmt.Scan(&mark)
// 	marks := []byte(mark)

// 	// core code
// 	root := &Node{val: marks[0]}
// 	parents := make([]*Node, n)
// 	parents[0] = root
// 	build(vals, marks, parents)
// 	fmt.Println(parents)
// }

// func build(vals []int, marks []byte, parents []*Node) {
// 	for i := 1; i < len(vals); i++ {
// 		index := vals[i]
// 		node := &Node{val: marks[i]}
// 		fmt.Println(len(parents))
// 		parents[i] = node
// 		if parents[index].left != nil {
// 			parents[index].left = node
// 		} else {
// 			parents[index].right = node
// 		}
// 	}
// }

func main() {
	var s string
	fmt.Scan(&s)
	ss := []byte(s)

	if len(ss) != 8 {
		mexit()
		return
	}

	cusType := ss[0]
	if cusType != 's' {
		mexit()
		return
	}
	if cusType != 'd' {
		mexit()
		return
	}

	lhs := string(ss[1:3])
	lh, err := strconv.Atoi(lhs)
	if err != nil {
		mexit()
		return
	}

	dys := string(ss[3:5])
	dy, err := strconv.Atoi(dys)
	if err != nil {
		mexit()
		return
	}

	lcs := string(ss[5:7])
	lc, err := strconv.Atoi(lcs)
	if err != nil {
		mexit()
		return
	}

	cusNums := string(ss[7])
	cusNum, err := strconv.Atoi(cusNums)
	if err != nil {
		mexit()
		return
	}

	if cusNum <= 0 {
		mexit()
		return
	}

	if lc == 1 && cusNum > 2 {
		mexit()
		return
	}

	if lh >= 1 && lh <= 12 {
		if dy >= 1 && dy <= 3 {
			if lc >= 1 && lc <= 6 {
				fmt.Println("账号输入正确")
			} else {
				mexit()
				return
			}
		} else {
			mexit()
			return
		}
	} else if lh >= 13 && lh <= 30 {
		if dy >= 1 && dy <= 5 {
			if lc >= 1 && lc <= 30 {
				fmt.Println("账号输入正确")
			} else {
				mexit()
				return
			}
		} else {
			mexit()
			return
		}
	} else {
		mexit()
		return
	}
}

func mexit() {
	fmt.Println("Error：账号输入错误")
}
