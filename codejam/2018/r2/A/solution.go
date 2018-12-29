// A great question, enjoy it a lot.
// Can reduce the question to two small questions:
// 1. How many balls, each column needs to give to its adjacent slots?
// 2. Giving that ^, how to construct the board?
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func abs(a int) int {
	if a > 0 {
		return a
	}
	return -a
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(final []int) (int, []string) {
	result, sum := []string{}, 0
	for _, d := range final {
		sum += d
	}
	if (sum != len(final)) || (final[0] == 0) || (final[len(final)-1] == 0) {
		return 0, []string{}
	}

	transform, extra := make([]int, len(final)), make([]int, len(final))
	for i, f := range final {
		cap := (extra[i] + 1) - (abs(transform[i]) + f)
		if cap > 0 {
			transform[i], extra[i+1] = cap, extra[i+1]+cap
		}
		if cap < 0 {
			transform[i+1], extra[i] = cap, extra[i]-cap
		}
	}

	// Borad construction
	layer := 1
	for _, t := range transform {
		layer = max(layer, abs(t)+1)
	}

	for i := 1; i <= layer; i++ {
		line := ""
		for _, t := range transform {
			if i > abs(t) {
				line = line + "."
				continue
			}
			if t > 0 {
				line = line + "\\"
				continue
			}

			line = line + "/"
		}
		result = append(result, line)
	}
	return layer, result
}

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
func main() {
	scanner.Split(bufio.ScanWords)
	caseCount := scanNum()
	for i := 0; i < caseCount; i++ {
		slotCount := scanNum()
		final := make([]int, slotCount)
		for j := 0; j < slotCount; j++ {
			final[j] = scanNum()
		}
		layer, lines := solve(final)
		if layer == 0 {
			fmt.Printf("Case #%d: IMPOSSIBLE\n", i+1)
			continue
		}
		fmt.Printf("Case #%d: %d\n", i+1, layer)
		for _, l := range lines {
			fmt.Println(l)
		}
	}
}
