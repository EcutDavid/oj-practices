package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func main() {
	scanner.Split(bufio.ScanWords)
	n := scanNum()
	idMap, L, R := map[int]int{}, -1, -1
	for i := 0; i < n; i++ {
		scanner.Scan()
		mode := scanner.Text()
		num := scanNum()
		if R == -1 {
			idMap[num], L, R = 0, 0, 0
			continue
		}
		if mode == "R" {
			idMap[num], R = R+1, R+1
		}
		if mode == "L" {
			idMap[num], L = L-1, L-1
		}
		if mode == "?" {
			c1, c2 := idMap[num]-L, R-idMap[num]
			if c1 < c2 {
				fmt.Println(c1)
			} else {
				fmt.Println(c2)
			}
		}
	}
}
