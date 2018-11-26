// A good graph problem.......
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
	n, r, x, y := scanNum(), scanNum(), scanNum(), scanNum()
	adjMap := map[int]map[int]bool{}
	for i := 0; i < r; i++ {
		u, v := scanNum(), scanNum()
		if adjMap[u] == nil {
			adjMap[u] = map[int]bool{}
		}
		if adjMap[v] == nil {
			adjMap[v] = map[int]bool{}
		}
		adjMap[u][v], adjMap[v][u] = true, true
	}

	bfs := func(i int, s []int) {
		q, v := []int{i}, map[int]bool{i: true}
		for len(q) > 0 {
			task, distance := q[0], s[q[0]]
			q = q[1:]
			for item := range adjMap[task] {
				if !v[item] {
					v[item] = true
					s[item] = distance + 1
					q = append(q, item)
				}
			}
		}
	}
	sX, sY := make([]int, n+1), make([]int, n+1)
	sX[x], sY[y] = 0, 0
	bfs(x, sX)
	bfs(y, sY)

	sum, shortest := 0, sX[x]+sY[x]
	for i := 1; i < n; i++ {
		for j := i + 1; j <= n; j++ {
			if adjMap[i][j] {
				continue
			}
			// If the relax result generate a shorter path then the current one,
			// it creates an "bad" case.
			iX, iY := sX[i], sY[i]
			if sX[j] < iX {
				iX = sX[j] + 1
			}
			if sY[j] < iY {
				iY = sY[j] + 1
			}
			if (iX + iY) >= shortest {
				sum++
			}
		}
	}
	fmt.Println(sum)
}
