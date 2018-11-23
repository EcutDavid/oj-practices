package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	uMap, max, sum := map[int]int{}, 0, 0
	for i := 0; i < n; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())

		uMap[num]++
		if uMap[num] > max {
			max = uMap[num]
		}
	}

	d := max / k
	if max%k > 0 {
		d++
	}
	for _, v := range uMap {
		sum += d*k - v
	}
	fmt.Println(sum)
}
