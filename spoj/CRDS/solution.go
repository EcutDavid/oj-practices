// A basic #math #newbie problem
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N, _ := strconv.Atoi(readLine())
	cache := [1e6 + 1]int{}
	lastCalcedLayer := 0

	for i := 0; i < N; i++ {
		level, _ := strconv.Atoi(readLine())
		if cache[level] != 0 {
			fmt.Println(cache[level])
			continue
		}

		for j := lastCalcedLayer + 1; j <= level; j++ {
			cache[j] = (cache[j-1] + 3*j - 1) % (1e6 + 7)
		}

		fmt.Println(cache[level])
		lastCalcedLayer = level
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
