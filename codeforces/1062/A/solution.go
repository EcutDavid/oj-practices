// Group the consecutive elements
// When a group start with 1 or end with 1000, it can contribute "length - 1" items.
// "length - 2" otherwise.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	g, cur := [][]int{[]int{-1}}, 0

	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		if g[cur][len(g[cur])-1] == num-1 {
			g[cur] = append(g[cur], num)
		} else {
			g = append(g, []int{num})
			cur++
		}
	}

	max := 0
	for _, v := range g {
		if len(v) < 2 {
			continue
		}
		l := 0
		if (v[0] == 1) || (v[len(v)-1] == 1000) {
			l = len(v) - 1
		} else {
			l = len(v) - 2
		}
		if l > max {
			max = l
		}
	}
	fmt.Println(max)
}
