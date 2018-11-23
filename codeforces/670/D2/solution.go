package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	n, k, scanner := 0, 0, bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())
	a, b := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}

	// Without int64, (l+r)/2 will break.
	answer, l, r := -1, int64(0), int64(2000000000)
	for l <= r {
		mid, match, newK := (l+r)/2, false, int64(k)
		for i := 0; i < len(a); i++ {
			extra := int64(a[i])*mid - int64(b[i])
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
			answer = int(mid)
		} else {
			r = mid - 1
		}
	}

	fmt.Println(answer)
}
