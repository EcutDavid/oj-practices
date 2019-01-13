package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
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
	f, width := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		f[i] = scanInt()
	}

	for i := 0; i < n; i++ {
		left, right := i, i
		for (left > 0) && (f[left-1] <= f[left]) {
			left--
		}
		for (right < (n - 1)) && (f[right+1] <= f[right]) {
			right++
		}
		width[i] = right - left + 1
	}
	fmt.Println(max(width...))
}
