package main

import (
	"fmt"
	"os"
)

func main() {
	num := 0
	fmt.Scan(&num)
	primeMap := map[int]int{}
	if num == 1 {
		fmt.Println("1 0")
		os.Exit(0)
	}

	for i := 2; i <= 1000; i++ {
		for num%i == 0 {
			num, primeMap[i] = num/i, primeMap[i]+1
		}
	}
	if num > 1 {
		primeMap[num]++
	}

	max := 0
	for _, v := range primeMap {
		if v > max {
			max = v
		}
	}

	finalValue := 1
	for k := range primeMap {
		finalValue *= k
	}

	allTheSame := true
	for _, v := range primeMap {
		if v != max {
			allTheSame = false
		}
	}

	step := 0
	tmp := 1
	for tmp < max {
		step, tmp = step+1, tmp*2
	}

	// In what condition, we need increase step?
	// 1. tmp > max, which means we need mul the num, does not matter whether "all the same"
	// 2. tmp == max, but is not "all the same", which means we still mul once
	if (tmp > max) || ((tmp == max) && !allTheSame) {
		step++
	}
	fmt.Println(finalValue, step)
}
