package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	n, o := scanNum(), scanNum()
	s := make([]int, n)
	for i := 0; i < n; i++ {
		s[i] = scanNum()
	}

	sort.Ints(s)
	cur, pointer := 0, 0
	for i := 0; i < o; i++ {
		// Move the pointer
		for (pointer < n) && (s[pointer] == cur) {
			pointer++
		}
		// Means all left ones are 0
		if pointer == n {
			fmt.Println(0)
			continue
		}
		fmt.Println(s[pointer] - cur)
		cur = s[pointer]
	}
}
