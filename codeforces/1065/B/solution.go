package main

import (
	"fmt"
	"math"
)

func main() {
	var m, n int64
	fmt.Scan(&n, &m)
	min := math.Max(float64(n-2*m), 0.0)

	connectedCount := int64(0)
	usedEdges := int64(0)
	for i := int64(1); i < n; i++ {
		if usedEdges >= m {
			break
		}
		usedEdges += i
		// The first edge connects two vertices, otherwise, every new vertex can use i edges.
		if connectedCount == 0 {
			connectedCount = 2
		} else {
			connectedCount++
		}
	}
	fmt.Println(min, n-connectedCount)
}
