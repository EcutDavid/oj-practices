package main

import (
	"fmt"
)

func main() {
	n, k, s, aCode := 0, 0, "", "A"[0]
	fmt.Scan(&n, &k, &s)

	codeCount := make([]int, k)
	for i := 0; i < n; i++ {
		codeCount[s[i]-aCode]++
	}

	min := 100000
	for i := 0; i < k; i++ {
		if codeCount[i] < min {
			min = codeCount[i]
		}
	}

	fmt.Println(min * k)
}
