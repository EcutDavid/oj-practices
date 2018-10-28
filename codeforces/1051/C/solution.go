package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	scanner.Scan()
	numMap := map[int]int{}
	indexMap := map[int]int{}
	isInA := []bool{}

	for i, raw := range strings.Split(scanner.Text(), " ") {
		num, _ := strconv.Atoi(raw)
		isInA = append(isInA, true)
		numMap[num]++
		if _, ok := indexMap[num]; ok == false {
			indexMap[num] = i
		}
	}

	niceNumsInA := 0
	// Indicates the first index for an item with more than 1 siblings
	thePowerIndex := -1
	even := false
	for k, v := range numMap {
		if v == 1 {
			niceNumsInA++
			if even {
				isInA[indexMap[k]] = false
			}
			even = !even
		}
		if v > 2 {
			thePowerIndex = indexMap[k]
		}
	}

	if niceNumsInA%2 == 0 {
		fmt.Println("YES")
		for _, v := range isInA {
			if v {
				fmt.Print("A")
			} else {
				fmt.Print("B")
			}
		}
		fmt.Println()
	} else if thePowerIndex > -1 {
		fmt.Println("YES")
		for i, v := range isInA {
			if i == thePowerIndex {
				fmt.Print("B")
				continue
			}
			if v {
				fmt.Print("A")
			} else {
				fmt.Print("B")
			}
		}
		fmt.Println()
	} else {
		fmt.Println("NO")
	}
}
