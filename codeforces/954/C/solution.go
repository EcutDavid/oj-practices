package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner, n := bufio.NewScanner(os.Stdin), 0
	scanner.Split(bufio.ScanWords)
	fmt.Scan(&n)
	a, max := make([]int, n), 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
		if a[i] > max {
			max = a[i]
		}
		if (i > 0) && (a[i-1] == a[i]) {
			// It is not allowed to stay in the same cell.
			fmt.Println("NO")
			os.Exit(0)
		}
	}

	y := 1
	for i := 0; i < (n - 1); i++ {
		d := a[i+1] - a[i]
		if d < 0 {
			d = -d
		}
		if d > 1 {
			if y == 1 {
				y = d
			}
			if y != d {
				fmt.Println("NO")
				os.Exit(0)
			}
		}
	}

	if y > 1 {
		// Handle the bad +1, -1
		for i := 0; i < (n - 1); i++ {
			isBadPlusOne := (a[i]%y == 0) && (a[i] == (a[i+1] - 1))
			isBadMinusOne := (a[i]%y == 1) && (a[i] == (a[i+1] + 1))
			if isBadMinusOne || isBadPlusOne {
				fmt.Println("NO")
				os.Exit(0)
			}
		}
	}

	// max > y because minA is 1
	fmt.Println("YES")
	if n == 1 {
		fmt.Println(max, y)
		os.Exit(0)
	}
	fmt.Println(int64(1e9), y)
}
