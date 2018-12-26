// Tried graph search the first, turns out it takes too much time,
// then find this one can be solved greedily with more careful thinking.
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	p, xs, ys := make([][2]int, 3), []int{}, []int{}

	for i := 0; i < 3; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		xs = append(xs, x)
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		p[i] = [2]int{x, y}
		ys = append(ys, y)
	}

	sort.Ints(xs)
	midX, midY := xs[1], -1
	for i := 0; i < 3; i++ {
		if p[i][0] == midX {
			midY = p[i][1]
		}
	}

	visited, count, res := map[[2]int]bool{}, 0, ""
	for i := 0; i < 3; i++ {
		for j := min(midY, p[i][1]); j <= max(midY, p[i][1]); j++ {
			if visited[[2]int{midX, j}] {
				continue
			}
			count++
			visited[[2]int{midX, j}] = true
			res += fmt.Sprintln(midX, j)
		}
	}

	for i := 0; i < 3; i++ {
		for j := min(midX, p[i][0]); j <= max(midX, p[i][0]); j++ {
			if visited[[2]int{j, p[i][1]}] {
				continue
			}
			count++
			visited[[2]int{j, p[i][1]}] = true
			res += fmt.Sprintln(j, p[i][1])
		}
	}
	fmt.Println(count)
	fmt.Println(res)
}
