package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func valiate(tar float64, a int, b []int) bool {
	for i := 0; i < len(b); i++ {
		cost := (tar + float64(a)) / float64(b[i])
		tar -= cost
		if tar < 0 {
			return false
		}
	}
	return true
}

func solve(a int, b []int) float64 {
	l, r, best, count := 0.0, 2e9, -1.0, 2000
	for l <= r && count > 0 {
		mid := (l + r) / 2
		count = count - 1
		// Works, means there is enough fuel
		if valiate(mid, a, b) {
			r, best = mid, mid
		} else {
			l = mid
		}
	}
	return best
}

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func main() {
	scanner.Split(bufio.ScanWords)
	n, a := scanNum(), scanNum()
	b := make([]int, n*2)
	for i := 0; i < n; i++ {
		b[i*2] = scanNum()
	}
	b[n*2-1] = scanNum()
	for i := 0; i < n-1; i++ {
		b[i*2+1] = scanNum()
	}

	res := solve(a, b)
	if res < 0 {
		fmt.Println(-1)
	} else {
		fmt.Println(res)
	}
}
