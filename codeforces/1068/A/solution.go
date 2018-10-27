package main

import (
	"fmt"
)

func main() {
	var N, M, K, L int64
	fmt.Scan(&N, &M, &K, &L)
	minCount := K + L
	if minCount > N {
		// Not enough coins to meet condition 3
		fmt.Println(-1)
	} else {
		// Cannot use math.Ceil here because float64 is not that acurate
		eachBuy := minCount / M
		if minCount%M > 0 {
			eachBuy++
		}
		// Not enough coins to meet condition 1
		if eachBuy*M > N {
			fmt.Println(-1)
		} else {
			fmt.Println(eachBuy)
		}
	}
}
