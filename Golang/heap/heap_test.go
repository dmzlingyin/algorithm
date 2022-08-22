package heap

import (
	"fmt"
	"testing"
)

func TestHeap(t *testing.T) {
	h := NewHeap(10)
	h.Insert(1)
	h.Insert(2)
	h.Insert(3)
	h.Insert(4)
	h.Insert(5)
	h.Insert(6)
	h.Insert(8)
	h.ExtractMax()
	h.ExtractMax()
	h.ExtractMax()
	h.ExtractMax()
	fmt.Println(h.data[1 : h.size+1])
}
