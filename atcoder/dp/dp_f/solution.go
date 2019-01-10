package main

import (
	"fmt"
	"math"
)

func max(nums ...int) int {
	res := math.MinInt32
	for _, num := range nums {
		if num > res {
			res = num
		}
	}
	return res
}

func main() {
	s, t := "", ""
	fmt.Scan(&s, &t)

	memo := make([][]int, len(s)+1)
	for i := 0; i <= len(s); i++ {
		memo[i] = make([]int, len(t)+1)
	}
	for i := 1; i <= len(s); i++ {
		for j := 1; j <= len(t); j++ {
			if s[i-1] == t[j-1] {
				memo[i][j] = memo[i-1][j-1] + 1
				continue
			}
			memo[i][j] = max(memo[i-1][j], memo[i][j-1])
		}
	}

	bestLen := memo[len(s)][len(t)]
	// Go backward to construct the solution
	solution := ""
	for i, j := len(s)-1, len(t)-1; len(solution) != bestLen; {

		if s[i] == t[j] {
			solution, i, j = s[i:i+1]+solution, i-1, j-1
			continue
		}
		if memo[i][j+1] > memo[i+1][j] {
			i--
		} else {
			j--
		}
	}
	fmt.Println(solution)
}
