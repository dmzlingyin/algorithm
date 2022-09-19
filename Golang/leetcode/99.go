package leetcode

// 恢复二叉搜索树
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func recoverTree(root *TreeNode) {
	p := root
	var pre, x, y *TreeNode

	stack := []*TreeNode{root}
	for len(stack) > 0 || p != nil {
		for p != nil {
			stack = append(stack, p)
			p = p.Left
		}

		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if pre != nil && node.Val < pre.Val {
			// x记录第一个位置错误的地方, y记录第二个位置错误的地方
			y = node
			if x == nil {
				x = pre
			} else {
				break
			}
		}
		pre = node
		p = node.Right
	}
	x.Val, y.Val = y.Val, x.Val
}
