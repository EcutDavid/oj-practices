// For each layer i , it can connect items in level (i + 1) + 2n,
// 	one should notice that for the layer i + 1, some nodes are
// 	already connected.
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
	adjList := map[int][]int{}

	for i := 0; i < n; i++ {
		scanner.Scan()
		e1, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		e2, _ := strconv.Atoi(scanner.Text())
		if adjList[e1] == nil {
			adjList[e1] = []int{}
		}
		if adjList[e2] == nil {
			adjList[e2] = []int{}
		}
		adjList[e1] = append(adjList[e1], e2)
		adjList[e2] = append(adjList[e2], e1)
	}

	// BFS to build the layer map
	v, q := map[int]bool{1: true}, []int{1}
	layerCount, layerMap, maxLayer := map[int]int{}, map[int]int{1: 0}, 0
	for len(q) > 0 {
		task := q[0]
		q = q[1:]
		layerCount[layerMap[task]]++

		for _, item := range adjList[task] {
			if v[item] {
				continue
			}
			layerMap[item] = layerMap[task] + 1
			if layerMap[item] > maxLayer {
				maxLayer = layerMap[item]
			}
			v[item] = true
			q = append(q, item)
		}
	}

	// Use eMap, oMap so that the next step does not need nesting loop.
	eMap, oMap := map[int]int64{}, map[int]int64{}
	for i := 0; i <= maxLayer; i++ {
		if i%2 == 1 {
			oMap[i] = oMap[i-2]
			oMap[i] += int64(layerCount[i])
			oMap[i+1] = oMap[i]
		} else {
			eMap[i] = eMap[i-2]
			eMap[i] += int64(layerCount[i])
			eMap[i+1] = eMap[i]
		}
	}

	sum := int64(0)
	for i := 0; i < maxLayer; i++ {
		sum += int64(layerCount[i]-1) * int64(layerCount[i+1])
		if i%2 == 0 {
			sum += int64(layerCount[i]) * (oMap[maxLayer] - oMap[i+1])
		} else {
			sum += int64(layerCount[i]) * (eMap[maxLayer] - eMap[i+1])
		}
	}
	fmt.Println(sum)
}
