// A basic #math problem
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

func isPrime(num int) bool {
	if num == 1 {
		return false
	}
	if num == 2 {
		return true
	}
	// A slight faster cuz no need to Sqrt...
	if num%2 == 0 {
		return false
	}
	ceil := int(math.Sqrt(float64(num)))
	for i := 3; i <= ceil; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	t, _ := strconv.Atoi(readLine())
	for i := 0; i < t; i++ {
		if i > 0 {
			fmt.Println()
		}
		l, r := 0, 0
		fmt.Sscanf(readLine(), "%d %d", &l, &r)
		for j := l; j <= r; j++ {
			if isPrime(j) {
				fmt.Println(j)
			}
		}
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
