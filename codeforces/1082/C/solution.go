// For each subject, we can gather the score list.
// Giving the score list, we can sort it, so best score when N students chosen can be found.
// Assume N students will participate each subjects, only select subjects that will give psotive result.
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
	n, m := scanNum(), scanNum()
	M := make([][]int, m+1)

	for i := 0; i < n; i++ {
		key, score := scanNum(), scanNum()
		if M[key] == nil {
			M[key] = []int{}
		}
		M[key] = append(M[key], score)
	}

	maxLen := 0
	for i := 0; i <= m; i++ {
		if len(M[i]) > maxLen {
			maxLen = len(M[i])
		}
	}
	bestScore := make([]int, maxLen+1)
	for i := 0; i <= m; i++ {
		sort.Ints(M[i])
		for j := len(M[i]) - 2; j >= 0; j-- {
			M[i][j] = M[i][j] + M[i][j+1]
		}
		for j := len(M[i]) - 1; j >= 0; j-- {
			if M[i][j] > 0 {
				bestScore[len(M[i])-j] += M[i][j]
			}
		}
	}

	max := 0
	for i := 1; i <= maxLen; i++ {
		if bestScore[i] > max {
			max = bestScore[i]
		}
	}

	fmt.Println(max)
}
