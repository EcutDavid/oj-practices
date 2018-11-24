// N number in total
// If l is odd, 1 * (N / 2) + last sepecial if there is any
// If l is even, -1 * (N / 2) + last sepecial if there is any
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(l, r int) {
	n := r - l + 1
	res := n / 2
	if l%2 == 0 {
		res *= -1
	}
	if n%2 == 1 {
		if r%2 == 1 {
			res -= r
		} else {
			res += r
		}
	}
	fmt.Println(res)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	q, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < q; i++ {
		scanner.Scan()
		l, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		r, _ := strconv.Atoi(scanner.Text())
		solve(l, r)
	}
}
