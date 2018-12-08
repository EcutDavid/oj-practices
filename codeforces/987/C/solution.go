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

func main() {
	scanner.Split(bufio.ScanWords)
	n := scanNum()
	a, b := make([]int, n), make([]int, n)
	memo := [][]int{[]int{}, b}
	for i := 0; i < n; i++ {
		a[i] = scanNum()
	}
	for i := 0; i < n; i++ {
		b[i] = scanNum()
	}

	for i := 2; i < 4; i++ {
		memo = append(memo, make([]int, n))
		for j := 0; j < n; j++ {
			memo[i][j] = int(1e8) * 4
		}
		for j := 0; j <= (n - i); j++ {
			best := int(1e8) * 4

			for k := j + 1; k < n; k++ {
				if (a[k] > a[j]) && (best > (b[j] + memo[i-1][k])) {
					best = b[j] + memo[i-1][k]
				}
			}

			memo[i][j] = best
		}
	}

	sort.Ints(memo[3])
	if memo[3][0] == int(1e8)*4 {
		fmt.Println(-1)
	} else {
		fmt.Println(memo[3][0])
	}
}
