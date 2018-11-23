package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := scanner.Text()
	a := len(s) / 20
	if len(s)%20 > 0 {
		a++
	}

	b, e := len(s)/a, len(s)%a
	if e > 0 {
		b++
	}
	fmt.Println(a, b)

	l := 0
	for i := 0; i < a; i++ {
		w := b
		if (e > 0) && (i >= e) {
			w--
			fmt.Print("*")
		}
		fmt.Println(s[l : l+w])
		l = l + w
	}
}
