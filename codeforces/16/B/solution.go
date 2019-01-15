package main

import (
	"fmt"
	"math"
)

func min(nums ...int) int {
	res := math.MaxInt32
	for _, num := range nums {
		if num < res {
			res = num
		}
	}
	return res
}

func main() {
	n, m, a, b, countMap := 0, 0, 0, 0, map[int]int{}
	fmt.Scan(&n, &m)

	for i := 0; i < m; i++ {
		fmt.Scan(&a, &b)
		countMap[b] += a
	}

	pointer, result := 10, 0
	for (n > 0) && (pointer > 0) {
		steal := min(n, countMap[pointer])
		result, n, pointer = result+steal*pointer, n-steal, pointer-1
	}

	fmt.Println(result)
}
