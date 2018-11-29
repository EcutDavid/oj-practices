// Use binary search to validate whether a time T works for the bots.
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
func main() {
	scanner.Split(bufio.ScanWords)
	c := scanNum()

	for i := 0; i < c; i++ {
		R, B, C := scanNum(), scanNum(), scanNum()
		cMeta := make([][3]int, C)
		for j := 0; j < C; j++ {
			cMeta[j] = [3]int{scanNum(), scanNum(), scanNum()}
		}

		l, r := int64(1), int64(1e9)*2*int64(B)
		best := r
		for l <= r {
			mid, cCapacity := (l+r)/2, make([]int, C)
			for j := 0; j < C; j++ {
				withoutLimit := max(0, mid-int64(cMeta[j][2])) / int64(cMeta[j][1])
				cCapacity[j] = int(min(int64(cMeta[j][0]), withoutLimit))
			}
			sort.Ints(cCapacity)
			load := int64(0)
			for j := 0; j < R; j++ {
				load += int64(cCapacity[len(cCapacity)-1-j])
			}

			if load >= int64(B) {
				r, best = mid-1, mid
			} else {
				l = mid + 1
			}
		}

		fmt.Printf("Case #%d: %d\n", i+1, best)
	}

}
