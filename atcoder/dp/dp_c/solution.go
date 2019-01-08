package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanInt := func() int {
		scanner.Scan()
		num, err := strconv.Atoi(scanner.Text())
		if err != nil {
			log.Fatal(err)
		}
		return num
	}
	n := scanInt()
	a, b, c, memo := make([]int, n), make([]int, n), make([]int, n), make([][3]int, n)
	for i := 0; i < n; i++ {
		a[i], b[i], c[i] = scanInt(), scanInt(), scanInt()
	}
	memo[0] = [3]int{a[0], b[0], c[0]}
	for i := 1; i < n; i++ {
		(&memo[i])[0] = max(memo[i-1][1], memo[i-1][2]) + a[i]
		(&memo[i])[1] = max(memo[i-1][0], memo[i-1][2]) + b[i]
		(&memo[i])[2] = max(memo[i-1][0], memo[i-1][1]) + c[i]
	}
	ans := max(max(memo[n-1][0], memo[n-1][1]), memo[n-1][2])
	fmt.Println(ans)
}
