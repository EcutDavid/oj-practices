package main

import (
	"fmt"
	"os"
)

func main() {
	x := 0
	fmt.Scan(&x)
	for a := 1; a <= x; a++ {
		for b := 1; b <= x; b++ {
			if (a%b > 0) || (a*b <= x) || (a/b == x) {
				continue
			}
			fmt.Println(a, b)
			os.Exit(0)
		}
	}
	fmt.Println(-1)
}
