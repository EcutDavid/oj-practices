package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func abs(a int) int {
	if a > 0 {
		return a
	}
	return -a
}

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
func main() {
	scanner.Split(bufio.ScanWords)
	n := scanNum()
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = scanNum()
	}
	min := math.MaxInt32
	for i := 0; i < n; i++ {
		sum := 0
		for j := 0; j < n; j++ {
			// Day
			sum += (abs(i-j) + j + i) * p[j]
			// Night
			sum += (i + j + abs(i-j)) * p[j]
		}
		if sum < min {
			min = sum
		}
	}
	fmt.Println(min)
}
