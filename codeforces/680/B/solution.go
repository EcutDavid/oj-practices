package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

const (
	a = iota
	c
	d
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

	n, index := scanInt(), scanInt()-1
	c := make([]bool, n)
	for i := 0; i < n; i++ {
		c[i] = scanInt() == 1
	}

	total := 0
	if c[index] {
		total = 1
	}
	for i := 1; i < 100; i++ {
		l, r := index-i, index+i
		if (l < 0) && (r >= n) {
			break
		}
		if (l >= 0) && (r < n) && c[l] && c[r] {
			total += 2
		}
		if (l >= 0) && (r >= n) && c[l] {
			total++
		}
		if (l < 0) && (r < n) && c[r] {
			total++
		}
	}
	fmt.Println(total)
}
