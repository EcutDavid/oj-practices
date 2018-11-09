package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	n, scanner := 0, bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	fmt.Scan(&n)
	a, b, pa, pb, sa, sb := make([]int, n+1), make([]int, n+1), 0, 0, int64(0), int64(0)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}
	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	sort.Sort(sort.Reverse(sort.IntSlice(b)))

	for i := 0; i < n; i++ {
		if a[pa] > b[pb] {
			sa += int64(a[pa])
			pa++
		} else {
			pb++
		}
		if b[pb] > a[pa] {
			sb += int64(b[pb])
			pb++
		} else {
			pa++
		}
	}
	fmt.Println(sa - sb)
}
