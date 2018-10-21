// A basic #math problem
// If num is 1, Shaktiman has no choice to move, which cause a failure.
// If an even number is given, Shaktiman can always choose to reduce the num to an odd.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	N, _ := strconv.Atoi(readLine())

	for i := 0; i < N; i++ {
		num, _ := strconv.Atoi(readLine())
		if num%2 == 0 {
			fmt.Println("Thankyou Shaktiman")
		} else {
			fmt.Println("Sorry Shaktiman")
		}
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
