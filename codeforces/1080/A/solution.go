package main

import (
	"fmt"
)

func main() {
	n, k := 0, 0
	fmt.Scan(&n, &k)
	// 2 red, 5 green, 8 blue
	p := [3]int{2 * n, 5 * n, 8 * n}
	sum := 0
	for i := 0; i < 3; i++ {
		sum += p[i] / k
		if p[i]%k > 0 {
			sum++
		}
	}
	fmt.Println(sum)
}
