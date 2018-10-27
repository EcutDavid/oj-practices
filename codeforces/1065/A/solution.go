package main

import (
	"fmt"
)

func main() {
	var t, s, a, b, c int64
	fmt.Scan(&t)
	for i := int64(0); i < t; i++ {
		fmt.Scan(&s, &a, &b, &c)
		pac := s / (a * c)
		left := s % (a * c)
		fmt.Println(pac*(a+b) + left/c)
	}
}
