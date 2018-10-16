// A simple #ad-hoc problem
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	digitMap := map[string]int{}
	for i := 0; i < 10; i++ {
		digitMap[strconv.Itoa(i)] = i
	}
	N, _ := strconv.Atoi(readLine())

	for i := 0; i < N; i++ {
		total := 0
		for _, d := range readLine() {
			total += digitMap[string(d)]
		}
		fmt.Println(total)
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
