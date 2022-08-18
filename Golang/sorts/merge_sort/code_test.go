package mergesort

import (
	"strconv"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestSort(t *testing.T) {
	assert := assert.New(t)
	tests := []struct {
		input    []int // 输入值
		expected []int // 期望值
	}{
		{[]int{7, 1, 3, 5, 2}, []int{1, 2, 3, 5, 7}},
		{[]int{-1, 0, 0, 3, -100}, []int{-100, -1, 0, 0, 3}},
	}

	for index, test := range tests {
		assert.Equal(test.expected, mergeSort(test.input), "Current test index is "+strconv.Itoa(index))
	}
}
