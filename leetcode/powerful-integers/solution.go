package main

import "math"

func powerfulIntegers(x int, y int, bound int) []int {
	xVal, yVal := map[int]bool{1: true}, map[int]bool{1: true}
	if x > 1 {
		cur := 1
		for {
			val := int(math.Pow(float64(x), float64(cur)))
			if val >= bound {
				break
			}
			xVal[val], cur = true, cur+1
		}
	}
	if y > 1 {
		cur := 1
		for {
			val := int(math.Pow(float64(y), float64(cur)))
			if val >= bound {
				break
			}
			yVal[val], cur = true, cur+1
		}
	}

	numMap := map[int]bool{}
	for i := range xVal {
		for j := range yVal {
			if (i + j) <= bound {
				numMap[i+j] = true
			}
		}
	}

	res := []int{}
	for n := range numMap {
		res = append(res, n)
	}
	return res
}

func main() {
}
