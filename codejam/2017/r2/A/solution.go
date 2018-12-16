// Solved this problem greedily
// that always choose the smallest group count to consume the products.
// For example, giving p = 3, group, 2 1 1 1 1, will prioritize [2, 1], instead of [1,1,1]
// Don't have confidence in math how it works for n > 3 though, but it indeed worked for the large case.
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func genWid1Choices(p int) []int {
	res := []int{}
	for i := 1; i < p; i++ {
		res = append(res, i)
	}
	return res
}

func genChoiceMap(p int) map[int][]map[int]int {
	cur := [][]int{}
	for _, v := range genWid1Choices(p) {
		cur = append(cur, []int{v})
	}
	res := map[int][]map[int]int{}
	for i := 0; i < (p - 1); i++ {
		extra, newCur := genWid1Choices(p), [][]int{}
		for _, v := range cur {
			for _, e := range extra {
				choice := append(v, e)
				newCur = append(newCur, choice)
				sum, choiceMap := 0, map[int]int{}
				for _, c := range choice {
					sum, choiceMap[c] = sum+c, choiceMap[c]+1
				}
				if sum%p == 0 {
					if res[i+2] == nil {
						res[i+2] = []map[int]int{}
					}
					res[i+2] = append(res[i+2], choiceMap)
				}
			}
		}
		cur = newCur
	}
	return res
}

func solve(g []int, p int) int {
	sum, gMap := 0, map[int]int{}
	for k, v := range g {
		g[k] = v % p
		if g[k] == 0 {
			sum++
		} else {
			gMap[g[k]]++
		}
	}

	choiceMap := genChoiceMap(p)
	for i := 2; i <= p; i++ {
		for _, c := range choiceMap[i] {
			choice := math.MaxInt32
			for k, v := range c {
				choice = min(gMap[k]/v, choice)
			}
			// fmt.Println("choice", choice)
			for k, v := range c {
				gMap[k] -= choice * v
			}
			// fmt.Println("gmap", gMap, sum)
			sum += choice
		}
	}

	left := 0
	for _, v := range gMap {
		left += v
	}
	if left > 0 {
		sum++
	}

	return sum
}

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
func main() {
	scanner.Split(bufio.ScanWords)
	n := scanNum()
	for i := 0; i < n; i++ {
		w, p := scanNum(), scanNum()
		g := make([]int, w)
		for j := 0; j < w; j++ {
			g[j] = scanNum()
		}
		result := solve(g, p)
		fmt.Printf("Case #%d: %d\n", i+1, result)
	}
}
