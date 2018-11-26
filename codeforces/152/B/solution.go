package main

import (
	"bufio"
	"fmt"
	"math"
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
	n, m, x, y, c, sum := scanNum(), scanNum(), scanNum(), scanNum(), scanNum(), int64(0)

	for i := 0; i < c; i++ {
		dx, dy, step := scanNum(), scanNum(), math.MaxInt32
		if dx != 0 {
			newStep := (n - x) / dx
			if dx < 0 {
				newStep = (x - 1) / -dx
			}
			if newStep < step {
				step = newStep
			}
		}
		if dy != 0 {
			newStep := (m - y) / dy
			if dy < 0 {
				newStep = (y - 1) / -dy
			}
			if newStep < step {
				step = newStep
			}
		}
		sum, x, y = sum+int64(step), x+step*dx, y+step*dy
	}

	fmt.Println(sum)
}
