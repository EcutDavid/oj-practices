package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func cost(a []int, i, j int) int {
	c := a[i] - a[j]
	if c < 0 {
		return -c
	}
	return c
}
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
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
	a, memo := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt()
	}

	memo[0], memo[1] = 0, cost(a, 0, 1)
	for i := 2; i < n; i++ {
		memo[i] = min(memo[i-1]+cost(a, i-1, i), memo[i-2]+cost(a, i-2, i))
	}

	fmt.Println(memo[n-1])
}
