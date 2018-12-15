package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func main() {
	scanner.Split(bufio.ScanWords)
	n, s := scanNum(), scanNum()
	v := make([]int64, n)
	min := int64(1e13)
	for i := int64(0); i < n; i++ {
		v[i] = scanNum()
		if v[i] < min {
			min = v[i]
		}
	}
	extra := int64(0)
	for i := int64(0); i < n; i++ {
		extra += v[i] - min
	}
	if extra >= s {
		fmt.Println(min)
		os.Exit(0)
	}

	cut := int64(math.Ceil(float64(s-extra) / float64(n)))
	if cut > min {
		fmt.Println(-1)
		os.Exit(0)
	}
	fmt.Println(min - cut)
}
