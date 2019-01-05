// For Parenthesis like "))))(())(((("
// We can scan twice(backward, forward) to get value like 4, 4 (producing 4 extra ")" and 4 extra "(")
// (Be careful "((): and ")((" is very different.)
// After get the meta data, we can start working on pairs.
// Wasted many time on forgot using `NewReaderSize` for big inputs.
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	open  = "("[0]
	close = ")"[0]
)

func calcSequence(s string) (int, int) {
	oCounter, cCounter, extraO, extraC := 0, 0, 0, 0

	for i := 0; i < len(s); i++ {
		if s[i] == close {
			cCounter++
		}
		if s[i] == open {
			if oCounter < cCounter {
				extraC, oCounter, cCounter = extraC+(cCounter-oCounter), 0, 0
			}
			oCounter++
		}
	}
	if cCounter > oCounter {
		extraC += cCounter - oCounter
	}

	oCounter, cCounter = 0, 0
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == open {
			oCounter++
		}
		if s[i] == close {
			if cCounter < oCounter {
				extraO, oCounter, cCounter = extraO+(oCounter-cCounter), 0, 0
			}
			cCounter++
		}
	}
	if oCounter > cCounter {
		extraO += oCounter - cCounter
	}

	return extraO, extraC
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	n := 0
	fmt.Scan(&n)
	reader := bufio.NewReaderSize(os.Stdin, 5*int(1e5))
	p := make([]string, n)
	for i := 0; i < n; i++ {
		s := ""
		fmt.Fscan(reader, &s)
		p[i] = s
	}

	pMap := map[[2]int]int{}
	for _, s := range p {
		o, c := calcSequence(s)
		if (o == 0) || (c == 0) {
			pMap[[2]int{o, c}]++
		}
	}

	sum := pMap[[2]int{0, 0}] / 2
	for k, v := range pMap {
		if k == [2]int{0, 0} {
			continue
		}
		negK := [2]int{k[1], k[0]}
		pairCount := min(v, pMap[negK])
		sum, pMap[k], pMap[negK] = sum+pairCount, pMap[k]-pairCount, pMap[negK]-pairCount
	}
	fmt.Println(sum)
}
