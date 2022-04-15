package kmp

import (
	"fmt"
	"testing"
)

func TestKmp(t *testing.T) {
	haystack := "aabaabaafa"
	needle := "aabaaf"
	pos := Kmp(haystack, needle)
	fmt.Println(pos)
}
