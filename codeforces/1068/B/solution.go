package main

import (
	"fmt"
	"math"
)

func main() {
	var b, res int64 = 0, 1
	fmt.Scan(&b)
	if b > 1 {
		// Count 1 and b itself.
		res++
		// Why Ceil instead of Floor? Example: 12
		sqrtB := int64(math.Ceil(math.Sqrt(float64(b))))
		if sqrtB*sqrtB == b {
			res++
		}

		for i := int64(2); i < sqrtB; i++ {
			if b%i == 0 {
				res += 2
			}
		}
	}
	fmt.Println(res)
}
