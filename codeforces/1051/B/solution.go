package main

import (
	"fmt"
)

func main() {
	var l, r int64
	fmt.Scan(&l, &r)
	fmt.Println("YES")
	for l < r {
		fmt.Println(l, l+1)
		l += 2
	}
}
