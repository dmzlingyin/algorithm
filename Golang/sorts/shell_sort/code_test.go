package shellsort

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type Test struct {
	Nums []int
	Exp  []int
}

func TestShellSort(t *testing.T) {
	tests := []Test{
		{[]int{-1, 3, 5, 0, 3, -4, 5}, []int{-4, -1, 0, 3, 3, 5, 5}},
		{[]int{-9, 8, 2, 8, 3, -4, 2}, []int{-9, -4, 2, 2, 3, 8, 8}},
		{[]int{-1, 3, 5, 1, 4, -8, 8}, []int{-8, -1, 1, 3, 4, 5, 8}},
	}

	for _, v := range tests {
		assert.Equal(t, v.Exp, shellsort(v.Nums), "test failed.")
	}
}
