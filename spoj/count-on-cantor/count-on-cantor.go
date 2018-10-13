// A simple #ad-hoc, #math problem.
// https://www.spoj.com/problems/CANTON/
// The pattern is: http://en.wikipedia.org/wiki/File:Diagonal_argument.svg
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(num int) string {
	level, count := 1, 0
	for (count + level) < num {
		count += level
		level++
	}

	move := num - count - 1
	if level%2 == 1 {
		return fmt.Sprintf("%v/%v", level-move, 1+move)
	} else {
		return fmt.Sprintf("%v/%v", 1+move, level-move)
	}
}

func main() {
	N, _ := strconv.Atoi(readLine())

	for i := 0; i < N; i++ {
		num, _ := strconv.Atoi(readLine())
		res := solve(num)
		fmt.Printf("TERM %v IS %s\n", num, res)
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
