package main

import (
	"fmt"
	"math"
)

func calcBitCount(num int64) int {
	count := 0
	for num > 0 {
		if num%2 == 1 {
			count++
		}
		num /= 2
	}
	return count
}

func main() {
	C := 0
	fmt.Scan(&C)
	for i := 0; i < C; i++ {
		num := int64(0)
		fmt.Scan(&num)
		if num == 0 {
			fmt.Println(1)
			continue
		}
		bitCount := calcBitCount(num)
		fmt.Println(int64(math.Exp2(float64(bitCount))))
	}
}
