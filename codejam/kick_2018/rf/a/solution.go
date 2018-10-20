// A basic ad-hoc problem
// https://code.google.com/codejam/contest/3314486/dashboard#s=p0
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func identity(src string) string {
	byteSli := []byte(src)
	for i := 1; i < len(byteSli); i++ {
		for j := i; j > 0; j-- {
			if byteSli[j-1] > byteSli[j] {
				byteSli[j-1], byteSli[j] = byteSli[j], byteSli[j-1]
			}
		}
	}
	return string(byteSli)
}

func main() {
	T, _ := strconv.Atoi(readLine())
	for i := 0; i < T; i++ {
		_, A, B := readLine(), readLine(), readLine()
		bCacheMap := map[string]bool{}
		for j := 1; j <= len(B); j++ {
			for k := 0; k <= (len(B) - j); k++ {
				bCacheMap[identity(B[k:k+j])] = true
			}
		}
		count := 0
		for j := 1; j <= len(B); j++ {
			for k := 0; k <= (len(B) - j); k++ {
				if bCacheMap[identity(A[k:k+j])] {
					count++
				}
			}
		}
		fmt.Printf("Case #%d: %d\n", i+1, count)
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
