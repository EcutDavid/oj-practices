// Using fmt.Scan and bufio.NewScanner(os.Stdin) at the same time caused
// exit with code 2 twice, not exactly sure why, but gonna stick that
// whenever bufio.NewScanner(os.Stdin) used, fmt.Scan should not be there.

// Believe the code can be simplified a lot but didn't dive deep.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.ParseInt(strings.Split(scanner.Text(), " ")[0], 10, 64)
	mid := (n*n + 1) / 2
	for scanner.Scan() {
		ws := strings.Split(scanner.Text(), " ")
		y, _ := strconv.ParseInt(ws[0], 10, 64)
		x, _ := strconv.ParseInt(ws[1], 10, 64)
		index := (int64(y)-1)*n + int64(x) - 1
		rank, extra := index/(2*n)*n, index%(2*n)
		if (x+y)%2 == 0 {
			if extra < n {
				rank += extra/2 + 1
			} else {
				rank += (extra%n+1)/2 + (n+1)/2
			}
			fmt.Println(rank)
		} else {
			if extra < n {
				rank += (extra + 1) / 2
			} else {
				rank += (extra%n+2)/2 + n/2
			}
			fmt.Println(mid + rank)
		}
	}
}
