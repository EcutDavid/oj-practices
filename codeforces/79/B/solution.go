package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)
var plants = [3]string{"Carrots", "Kiwis", "Grapes"}

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
func main() {
	scanner.Split(bufio.ScanWords)
	_, m, k, t := scanNum(), scanNum(), scanNum(), scanNum()
	W, M := make([]int, k), map[int]bool{}
	for i := 0; i < k; i++ {
		W[i] = (scanNum()-1)*m + scanNum()
		M[W[i]] = true
	}
	sort.Ints(W)

	for i := 0; i < t; i++ {
		q := (scanNum()-1)*m + scanNum()
		if M[q] {
			fmt.Println("Waste")
			continue
		}

		wSum := 0
		for j := 0; j < k; j++ {
			if W[j] > q {
				break
			}
			wSum++
		}

		fmt.Println(plants[(q-wSum-1)%3])
	}
}
