// A basic #dynamic-programming problem, think twice about what's happening when a character is 0
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	for {
		line := readLine()
		if line == "0" {
			break
		}
		memo := make([]int64, len(line)+1)
		memo[0], memo[1] = 1, 1
		for i := 1; i < len(line); i++ {
			if line[i:i+1] == "0" {
				memo[i+1] = memo[i-1]
				continue
			}
			num, _ := strconv.Atoi(line[i-1 : i+1])
			if num > 9 && num < 27 {
				memo[i+1] = memo[i] + memo[i-1]
			} else {
				memo[i+1] = memo[i]
			}
		}
		fmt.Println(memo[len(line)])
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
