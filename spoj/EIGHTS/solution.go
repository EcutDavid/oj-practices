// A basic #math problem
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	t, _ := strconv.Atoi(readLine())

	theFour := []int64{192, 442, 692, 942}
	for i := 0; i < t; i++ {
		num, _ := strconv.ParseInt(readLine(), 10, 64)
		num--
		fmt.Println(theFour[num%4] + 1000*(num/4))
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
