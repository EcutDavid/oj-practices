package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func main() {
	scanner.Split(bufio.ScanWords)
	n := scanNum()
	res := []string{}
	// n is also gen the final 2 n n+1
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanNum()
	}
	counter := 0
	for i := 1; i < n; i++ {
		if a[i] > a[i-1] {
			counter++
		}
	}

	sum, width := 0, n+1
	for i := n - 1; i >= 0; i-- {
		if (a[i]+sum)%width == i {
			continue
		}
		add := i - (a[i]+sum)%width
		if add < 0 {
			add += width
		}
		res = append(res, fmt.Sprintln(1, i+1, add))
		sum = (sum + add) % width
	}
	if len(res) == 0 {
		fmt.Println(0)
	} else {
		fmt.Println(len(res) + 1)
		for _, v := range res {
			fmt.Print(v)
		}
		fmt.Println(2, n, width)
	}
}
