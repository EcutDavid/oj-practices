// Observed that, distribute the weight to root and levies only will generate the best result.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func scanNum(s *bufio.Scanner) int {
	s.Scan()
	num, _ := strconv.Atoi(s.Text())
	return num
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	n, s := scanNum(scanner), scanNum(scanner)
	adjList, inDegree := map[int]map[int]bool{}, map[int]int{}
	for i := 0; i < n; i++ {
		a, b := scanNum(scanner), scanNum(scanner)
		if adjList[a] == nil {
			adjList[a] = map[int]bool{}
		}
		if adjList[b] == nil {
			adjList[b] = map[int]bool{}
		}
		adjList[a][b], adjList[b][a] = true, true
		inDegree[a], inDegree[b] = inDegree[a]+1, inDegree[b]+1
	}
	root := -1
	for k, v := range inDegree {
		if v == 1 {
			root = k
			break
		}
	}

	leafCount, visited, queue := 0, map[int]bool{root: true}, []int{root}
	for len(queue) > 0 {
		task, count := queue[0], 0
		queue = queue[1:]
		for n := range adjList[task] {
			if visited[n] {
				continue
			}
			visited[n], count, queue = true, count+1, append(queue, n)
		}
		if count == 0 {
			leafCount++
		}
	}

	fmt.Printf("%.11f\n", float64(s)/float64(leafCount+1)*2.0)
}
