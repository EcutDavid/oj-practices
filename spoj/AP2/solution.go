// A basic #math problem
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	t, _ := strconv.Atoi(readLine())
	for i := 0; i < t; i++ {
		var l, r, s uint64
		fmt.Sscanf(readLine(), "%d %d %d", &l, &r, &s)

		length := s * 2 / (l + r)
		// The series will have at least 7 elements.
		inc := (r - l) / (length - 5)
		start := l - 2*inc

		output := ""
		for j := uint64(0); j < length; j++ {
			if j > 0 {
				output = output + " "
			}
			output = output + strconv.FormatUint(start+inc*j, 10)
		}

		fmt.Println(length)
		fmt.Println(output)
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
