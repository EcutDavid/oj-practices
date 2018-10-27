// A basic #math #newbie problem
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	for {
		a, b, c := 0, 0, 0
		fmt.Sscanf(readLine(), "%d %d %d", &a, &b, &c)
		if a == 0 && b == 0 && c == 0 {
			break
		}
		if (b - a) == (c - b) {
			fmt.Println("AP", b-a+c)
		} else {
			fmt.Println("GP", b/a*c)
		}
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
