package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func max(a, b int64) int64 {
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

	N, W := scanInt(), scanInt()
	w, v := make([]int, N), make([]int, N)
	for i := 0; i < N; i++ {
		w[i], v[i] = scanInt(), scanInt()
	}
	memo := make([][]int64, N+1)
	for i := 0; i < N+1; i++ {
		memo[i] = make([]int64, W+1)
	}

	for i := 1; i <= N; i++ {
		for j := 1; j <= W; j++ {
			if w[i-1] > j {
				memo[i][j] = memo[i-1][j]
				continue
			}
			memo[i][j] = max(memo[i-1][j], memo[i-1][j-w[i-1]]+int64(v[i-1]))
		}
	}

	fmt.Println(memo[N][W])
}
