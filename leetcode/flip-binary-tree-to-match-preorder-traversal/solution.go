package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func swap(parent *TreeNode) {
	parent.Left, parent.Right = parent.Right, parent.Left
}

func walk(node, parent *TreeNode, voyage, flips []int, cur int) ([]int, int) {
	if node == nil {
		return flips, cur - 1
	}
	if node.Val != voyage[cur] {
		if parent == nil {
			return flips, -1
		}
		if (parent.Right == node) || (parent.Right == nil) || (parent.Right.Val != voyage[cur]) {
			return flips, -1
		}
		swap(parent)
		flips = append(flips, parent.Val)
		fmt.Println(flips)
		node = parent.Left
	}

	flips, cur = walk(node.Left, node, voyage, flips, cur+1)
	if cur == -1 {
		return flips, -1
	}
	flips, cur = walk(node.Right, node, voyage, flips, cur+1)
	if cur == -1 {
		return flips, -1
	}
	return flips, cur
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flipMatchVoyage(root *TreeNode, voyage []int) []int {
	flips, cur := walk(root, nil, voyage, []int{}, 0)
	if cur == -1 {
		return []int{-1}
	}
	return flips
}

func main() {
}
