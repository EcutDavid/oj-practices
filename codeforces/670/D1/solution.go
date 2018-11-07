// Using binary search to validate the "answers" within lg(n) times.
// This solution is far away from solving D2 :(
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	n, k, scanner := 0, 0, bufio.NewScanner(os.Stdin)
	fmt.Scan(&n, &k)
	scanner.Split(bufio.ScanWords)
	a, b := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}

	answer, l, r := -1, 0, 2000
	for l <= r {
		mid, match, newK := (l+r)/2, false, k
		for i := 0; i < len(a); i++ {
			extra := a[i]*mid - b[i]
			if extra > newK {
				break
			} else if extra > 0 {
				newK -= extra
			}
			if i == (len(a) - 1) {
				match = true
			}
		}
		if match {
			l = mid + 1
			answer = mid
		} else {
			r = mid - 1
		}
	}

	fmt.Println(answer)
}
