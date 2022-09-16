package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// func main() {
// scanner := bufio.NewScanner(os.Stdin)
// scanner.Scan()
// s := scanner.Text()
// s1 := reverse(s, 0, len(s)-1)
// s2 := strings.Split(s1, " ")
// res := ""
// for _, v := range s2 {
// 	res += reverse(v, 0, len(v)-1) + " "
// }
// fmt.Println(res)

// }

// func reverse(s string, i, j int) string {
// 	sb := []byte(s)
// 	for i < j {
// 		sb[i], sb[j] = sb[j], sb[i]
// 		i++
// 		j--
// 	}
// 	return string(sb)
// }

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	input := sc.Text()
	nums := strings.Split(input, ", ")
	nums1 := strings.Split(nums[0][1:len(nums[0])-1], ",")
	nums2 := strings.Split(nums[1][1:len(nums[1])-1], ",")
	hash1 := map[string]int{}
	hash2 := map[string]int{}
	res := []string{}

	for _, v := range nums1 {
		hash1[v]++
	}
	for _, v := range nums2 {
		if _, ok := hash1[v]; ok {
			if _, ok := hash2[v]; !ok {
				hash2[v]++
				res = append(res, v)
			}
		}
	}
	fmt.Println(res)
}
