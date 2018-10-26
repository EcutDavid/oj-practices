package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	readLine()
	line := readLine()
	isDiverse := false
	for i := 0; i < (len(line) - 1); i++ {
		if line[i] != line[i+1] {
			fmt.Println("YES")
			fmt.Println(line[i : i+2])
			isDiverse = true
			break
		}
	}
	if !isDiverse {
		fmt.Println("NO")
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
