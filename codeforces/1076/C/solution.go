package main

import (
	"bufio"
	"fmt"
	"os"
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
	for i := 0; i < n; i++ {
		d := scanNum()
		if d == 0 {
			fmt.Println("Y 0.000000000 0.000000000")
			continue
		}
		if d == 1 {
			fmt.Println("N")
			continue
		}
		l, r, mid := 1.0, float64(d)/2, 1.0
		for c := 0; c < 50000; c++ {
			mid = (l + r) / 2
			if mid*(float64(d)-mid) < float64(d) {
				l = mid
			} else {
				r = mid
			}
		}
		diff := (float64(d)-mid)*mid - float64(d)
		if diff*diff > 1e-12 {
			fmt.Println("N")
			continue
		}
		fmt.Println("Y", float64(d)-mid, mid)
	}
}
