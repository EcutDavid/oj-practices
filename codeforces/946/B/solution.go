package main

import (
	"fmt"
)

func main() {
	var a, b int64
	fmt.Scan(&a, &b)
	for (a != 0) && (b != 0) && ((a >= 2*b) || (b >= 2*a)) {
		if a >= 2*b {
			a %= 2 * b
		} else {
			b %= 2 * a
		}
	}
	fmt.Println(a, b)
}
