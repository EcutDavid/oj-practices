package main

import (
	"fmt"
)

func main() {
	n, s := 0, ""
	fmt.Scan(&n, &s)
	c, b := map[byte]int{}, make([]byte, n)
	for i := 0; i < n; i++ {
		c[s[i]]++
	}

	pointer := 0
	for k, v := range c {
		for i := 0; i < v; i++ {
			b[i+pointer] = k
		}
		pointer += v
	}
	fmt.Println(string(b))
}
