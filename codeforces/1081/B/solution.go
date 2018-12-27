package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	g, nums, res := map[int]int{}, make([]int, n), []string{}

	for i := 0; i < n; i++ {
		nums[i] = n - scanNum()
		g[nums[i]]++
	}

	for k, v := range g {
		if v%k != 0 {
			fmt.Println("Impossible")
			os.Exit(0)
		}
	}

	counter, hats, cur := map[int]int{}, map[int]int{}, 1

	for _, d := range nums {
		if (hats[d] == 0) || (counter[hats[d]] == d) {
			hats[d], cur = cur, cur+1
		}
		res = append(res, strconv.Itoa(hats[d]))
		counter[hats[d]]++
	}

	fmt.Println("Possible")
	fmt.Println(strings.Join(res, " "))
}
