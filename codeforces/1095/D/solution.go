package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
func main() {
	scanner.Split(bufio.ScanWords)
	n := scanNum()
	if n == 3 {
		fmt.Println("1 2 3")
		os.Exit(0)
	}
	a := make([][2]int, n+1)
	for i := 0; i < n; i++ {
		a[i+1] = [2]int{scanNum(), scanNum()}
	}

	res := []int{1}
	for len(res) < n {
		cur := res[len(res)-1]
		c1, c2 := a[cur][0], a[cur][1]
		next := c1

		c2IsNext := (a[c1][0] != c2) && (a[c1][1] != c2)
		if c2IsNext {
			next = c2
		}

		res = append(res, next)
	}

	fmt.Print(res[0])
	for i := 1; i < n; i++ {
		fmt.Printf(" %d", res[i])
	}
	fmt.Println()
}
