package heap

type Heap struct {
	data     []int
	size     int
	capacity int
}

func Heapify(arr []int) Heap {
	n := len(arr)
	h := NewHeap(n)
	copy(h.data[1:], arr)
	h.size = n

	for i := n / 2; i >= 1; i-- {
		h.ShiftDown(i)
	}
	return h
}

func NewHeap(capacity int) Heap {
	return Heap{
		data:     make([]int, capacity+1),
		size:     0,
		capacity: capacity,
	}
}

func (h *Heap) Insert(v int) {
	if h.size+1 > h.capacity {
		return
	}
	h.data[h.size+1] = v
	h.size++
	h.ShiftUp(h.size)
}

func (h *Heap) ExtractMax() int {
	if h.isEmpty() {
		panic("heap is empty")
	}

	v := h.data[1]
	h.Swap(1, h.size)
	h.size--
	h.ShiftDown(1)
	return v
}

func (h *Heap) ShiftDown(k int) {
	for k*2 <= h.size {
		j := 2 * k
		if j < h.size && h.data[j+1] > h.data[j] {
			j++
		}
		if h.data[j] < h.data[k] {
			break
		}
		h.Swap(k, j)
		k = j
	}
}

// 核心代码
func (h *Heap) ShiftUp(i int) {
	for i > 1 && h.data[i/2] < h.data[i] {
		h.Swap(i, i/2)
		i /= 2
	}
}

func (h *Heap) Size() int {
	return h.size
}

func (h *Heap) isEmpty() bool {
	return h.size == 0
}

func (h *Heap) Swap(i, j int) {
	h.data[i], h.data[j] = h.data[j], h.data[i]
}
