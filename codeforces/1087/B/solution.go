// Find all the positive integers that smaller than k that divides n, can calc the result from there.
package main

import (
	"fmt"
	"math"
)

func main() {
	n, k, best := 0, 0, math.MaxInt32
	fmt.Scan(&n, &k)

	for modRes := 1; modRes < k; modRes++ {
		if n%modRes != 0 {
			continue
		}

		divRes := n / modRes
		potentialNum := divRes*k + modRes

		if potentialNum < best {
			best = potentialNum
		}
	}

	fmt.Println(best)
}
