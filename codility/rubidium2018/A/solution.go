package main

import (
	"fmt"
	"math"
)

// you can also use imports, for example:
// import "fmt"
// import "os"

// you can write to stdout for debugging purposes, e.g.
// fmt.Println("this is a debug message")

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func getMaxD(xA, yA, xB, yB int) int {
	return max(abs(xA-xB)/2, abs(yA-yB)/2)
}

func Solution(X []int, Y []int) int {
	d, N := math.MaxInt32, len(X)
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			d = min(getMaxD(X[i], Y[i], X[j], Y[j]), d)
		}
	}
	return d
}

func main() {
	fmt.Println(Solution([]int{0, 0, 10, 10}, []int{0, 10, 0, 10}))
	fmt.Println(Solution([]int{1, 1, 8}, []int{1, 6, 0}))
}
