package main

import (
	"fmt"
)

func main() {
	var b, res int64
	fmt.Scan(&b)
	for i := int64(1); i <= b; i++ {
		if 1e10%i == 0 {
			res++
		}
	}
	fmt.Println(res)
}
