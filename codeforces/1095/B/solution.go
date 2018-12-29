package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	scanner.Split(bufio.ScanWords)
	n := scanNum()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanNum()
	}
	if n == 2 {
		fmt.Println(0)
		os.Exit(0)
	}
	sort.Ints(a)
	fmt.Println(min(a[len(a)-2]-a[0], a[len(a)-1]-a[1]))
}
