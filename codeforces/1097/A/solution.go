package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	rank, suit := scanner.Text()[0], scanner.Text()[1]
	for i := 0; i < 5; i++ {
		scanner.Scan()
		if scanner.Text()[0] == rank || scanner.Text()[1] == suit {
			fmt.Println("YES")
			os.Exit(0)
		}
	}
	fmt.Println("NO")
}
