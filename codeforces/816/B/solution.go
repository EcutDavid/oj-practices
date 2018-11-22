package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func lowerBound(src []int, tar int) int {
	index, l, r := -1, 0, len(src)-1
	for l <= r {
		mid := (l + r) / 2
		if src[mid] < tar {
			l = mid + 1
		} else {
			r = mid - 1
			index = mid
		}
	}
	return index
}

func upperBound(src []int, tar int) int {
	index, l, r := -1, 0, len(src)-1
	for l <= r {
		mid := (l + r) / 2
		if src[mid] <= tar {
			l = mid + 1
			index = mid
		} else {
			r = mid - 1
		}
	}
	return index
}

func main() {
	n, k, q := 0, 0, 0
	fmt.Scan(&n, &k, &q)
	l, r, count := make([]int, n), make([]int, n), make([]int, 200001)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	for i := 0; i < n; i++ {
		scanner.Scan()
		l[i], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		r[i], _ = strconv.Atoi(scanner.Text())
	}
	sort.Ints(l)
	sort.Ints(r)
	for i := 1; i <= 200000; i++ {
		count[i] = count[i-1]
		lb := lowerBound(r, i)
		ub := upperBound(l, i)
		if (lb != -1) && (ub != -1) && ((ub - lb + 1) >= k) {
			count[i]++
		}
	}

	for i := 0; i < q; i++ {
		scanner.Scan()
		qL, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		qR, _ := strconv.Atoi(scanner.Text())
		fmt.Println(count[qR] - count[qL-1])
	}
}
