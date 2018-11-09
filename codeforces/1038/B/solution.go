// Find the answer by looking at n(n + 1)/2
package main

import (
	"fmt"
	"os"
)

func main() {
	n := 0
	fmt.Scan(&n)
	if n <= 2 {
		fmt.Println("No")
		os.Exit(0)
	} else {
		fmt.Println("Yes")
	}

	choice := 0
	if n%2 == 0 {
		choice = n / 2
	} else {
		choice = (n + 1) / 2
	}

	fmt.Println("1", choice)
	fmt.Print(n - 1)
	for i := 1; i <= n; i++ {
		if i == choice {
			continue
		}
		fmt.Printf(" %d", i)
	}
	fmt.Println()
}
