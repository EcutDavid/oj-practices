package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanInt := func() int {
		scanner.Scan()
		num, err := strconv.Atoi(scanner.Text())
		if err != nil {
			log.Fatal(err)
		}
		return num
	}

	n, k := scanInt(), scanInt()
	t := make([]int, n)
	for i := 0; i < n; i++ {
		t[i] = scanInt()
	}
	sort.Ints(t)

	min := math.MaxInt32
	for i := 0; i < (n - k + 1); i++ {
		diff := t[i+k-1] - t[i]
		if min > diff {
			min = diff
		}
	}
	fmt.Println(min)
}
