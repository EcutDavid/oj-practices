// TIL, using the default Split func(bufio.ScanLines), will break due to the line is too large.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	m := map[string]int{}
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	for i := 1; i <= n; i++ {
		scanner.Scan()
		m[scanner.Text()] = i
	}

	top := 0
	result := []string{}
	for i := 1; i <= n; i++ {
		scanner.Scan()
		newTop := m[scanner.Text()]
		if newTop > top {
			result = append(result, strconv.Itoa(newTop-top))
			top = newTop
		} else {
			result = append(result, "0")
		}
	}
	fmt.Println(strings.Join(result, " "))
}
