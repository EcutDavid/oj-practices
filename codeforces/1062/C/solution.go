// Giving a 1 inside the input with length N, it can contribute {1, 1, 2, 4, 8 ...}
// Forgot the "+ m" at line 36 spent me 1 hour.
package main

import (
	"bufio"
	"fmt"
	"os"
)

const m = 1000000007

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1000000)
	n, q, line := 0, 0, ""
	fmt.Fscanf(reader, "%d %d\n%s\n", &n, &q, &line)

	cMap, oneMap := map[int]int{0: 1, 1: 1}, map[int]int{0: 0}
	for i := 1; i <= n; i++ {
		oneMap[i] = oneMap[i-1]
		if line[i-1:i] == "1" {
			oneMap[i]++
		}
	}
	for i := 2; i <= (n + 1); i++ {
		cMap[i] = cMap[i-1] * 2 % m
	}

	for i := 0; i < q; i++ {
		l, r := 0, 0
		fmt.Fscanf(reader, "%d %d\n", &l, &r)

		width, oneCount := r-l+1, oneMap[r]-oneMap[l-1]
		sum := 0
		if oneCount > 0 {
			sum = (cMap[width+1] + m - cMap[width-oneCount+1]) % m
		}

		fmt.Println(sum)
	}
}
