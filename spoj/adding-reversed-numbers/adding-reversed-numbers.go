// A simple #ad-hoc problem.
// https://www.spoj.com/problems/ADDREV/
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func revNum(num int) (res int) {
	if num%10 == 0 {
		num /= 10
	}
	for num > 0 {
		res = res*10 + num%10
		num /= 10
	}
	return res
}

func main() {
	N, _ := strconv.Atoi(readLine())

	for i := 0; i < N; i++ {
		nums := [2]int{}
		for i, raw := range strings.Split(readLine(), " ") {
			nums[i], _ = strconv.Atoi(raw)
		}
		res := revNum(revNum(nums[0]) + revNum(nums[1]))
		fmt.Println(res)
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
