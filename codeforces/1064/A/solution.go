package main

import (
	"fmt"
	"os"
	"sort"
)

func main() {
	a, b, c := 0, 0, 0
	fmt.Scan(&a, &b, &c)
	d := []int{a, b, c}
	sort.Ints(d)
	if (d[2] + 1) <= (d[1] + d[0]) {
		fmt.Println(0)
		os.Exit(0)
	}
	fmt.Println((d[2] + 1) - (d[1] + d[0]))
}
