// A good array questions!
package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
)

// // Returns the mapping between the length of "selection" to the min-sum.
// func parseChoice(nums []int) map[int]int {
// 	choice := map[int]int{}
// 	for i := 1; i <= len(nums); i++ {
// 		min := math.MaxInt32
// 		for j := 0; j < (len(nums) - i + 1); j++ {
// 			sum := 0
// 			for k := 0; k < i; k++ {
// 				sum += nums[j+k]
// 			}
// 			if min > sum {
// 				min = sum
// 			}
// 		}
// 		choice[i] = min
// 	}
// 	return choice
// }

// Returns the mapping between the length of "selection" to the min-sum.
func parseChoice(nums []int) map[int]int {
	choice := map[int]int{}
	// Optimization
	last := map[int]int{}
	for i := 1; i <= len(nums); i++ {
		min := math.MaxInt32
		for j := 0; j < (len(nums) - i + 1); j++ {
			sum := last[j] + nums[j+i-1]
			if min > sum {
				min = sum
			}
			last[j] = sum
		}
		choice[i] = min
	}
	return choice
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanInt := func() int {
		scanner.Scan()
		num, err := strconv.Atoi(scanner.Text())
		if err != nil {
			log.Fatal(err)
		}
		return num
	}

	n, m := scanInt(), scanInt()
	a, b := make([]int, n), make([]int, m)
	for i := 0; i < n; i++ {
		a[i] = scanInt()
	}
	for i := 0; i < m; i++ {
		b[i] = scanInt()
	}
	x := scanInt()

	choiceA, choiceB := parseChoice(a), parseChoice(b)

	bestS := 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if int64(choiceA[i])*int64(choiceB[j]) > int64(x) {
				continue
			}
			if i*j > bestS {
				bestS = i * j
			}
		}
	}

	fmt.Println(bestS)
}
