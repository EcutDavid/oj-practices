package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
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

	n, k := scanInt(), scanInt()
	a, memo := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt()
	}

	memo[0] = 0
	for i := 1; i < n; i++ {
		memo[i] = math.MaxInt32
		for j := 1; j <= k; j++ {
			if i-j < 0 {
				break
			}
			memo[i] = min(memo[i-j]+cost(a, i-j, i), memo[i])
		}
	}

	fmt.Println(memo[n-1])
}
