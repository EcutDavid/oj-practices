package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 300000)
	n, s := 0, ""
	fmt.Fscanf(reader, "%d\n%s\n", &n, &s)
	for i := 0; i < (len(s) - 1); i++ {
		if s[i] > s[i+1] {
			fmt.Println(s[:i] + s[i+1:])
			os.Exit(0)
		}
	}
	fmt.Println(s[:len(s)-1])
}
