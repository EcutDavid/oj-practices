// 1. Only care about a and b.
// 2. Can break the input into a groups.
// 3. Can only care about the very next group.
package main

import (
	"bufio"
	"fmt"
	"os"
)

type i64 int64

var (
	ascA   = "a"[0]
	ascB   = "b"[0]
	modulo = i64(1e9) + 7
)

func main() {
	s := ""
	reader := bufio.NewReaderSize(os.Stdin, int(1e5))
	fmt.Fscanf(reader, "%s", &s)
	b, width := make([]bool, len(s)), 0
	for i := 0; i < len(s); i++ {
		if s[i] == ascA || s[i] == ascB {
			b[width], width = s[i] == ascA, width+1
		}
	}

	aGroup := []int{}
	for i := 0; i < width; i++ {
		count := 0
		for (i < width) && b[i] {
			count, i = count+1, i+1
		}
		if count > 0 {
			aGroup = append(aGroup, count)
		}
	}

	if len(aGroup) == 0 {
		fmt.Println(0)
		os.Exit(0)
	}

	sum := i64(aGroup[0])
	for i := 1; i < len(aGroup); i++ {
		sum = (sum + i64(aGroup[i]) + sum*i64(aGroup[i])) % modulo
	}
	fmt.Println(sum)
}
