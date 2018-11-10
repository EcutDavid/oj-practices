package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	n, l, a, e, scanner := 0, 0, 0, 0, bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	fmt.Scan(&n, &l, &a)
	q := make([][2]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		q[i][0], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		q[i][1], _ = strconv.Atoi(scanner.Text())
	}

	total := 0
	for i := 0; i < n; i++ {
		total += (q[i][0] - e) / a
		e = q[i][0] + q[i][1]
	}
	total += (l - e) / a

	fmt.Println(total)
}
