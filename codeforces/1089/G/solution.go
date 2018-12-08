// The tricky part of this question is that for N belongs to [2, 6]
// To get the max classes a student can finish in N days, the answer cannot found in the loop "B B B.."(7 bool values).
// Example: "1 0 0 1 0 0 1" the max classes in 2 days, is 2 instead of 1.
// You have to loop two connected weeks to get the expected value.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(class []bool, dayCount int) {
	classInAWeek, within := 0, make([]int, len(class)+1)
	for i := 0; i < 7; i++ {
		if class[i] {
			classInAWeek++
		}
	}

	for i := 1; i < len(class)+1; i++ {
		bestWithinSum := 0
		for j := 0; j < (len(class) - i); j++ {
			withinSum := 0
			for k := 0; k < i; k++ {
				if class[j+k] {
					withinSum++
				}
			}
			if withinSum > bestWithinSum {
				bestWithinSum = withinSum
			}
		}

		// Since i is in increasing order, the first discovered i is the best answer.
		if within[bestWithinSum] == 0 {
			within[bestWithinSum] = i
		}
	}
	if classInAWeek >= dayCount {
		fmt.Println(within[dayCount])
		return
	}

	div, rem := dayCount/classInAWeek, dayCount%classInAWeek
	if rem == 0 {
		div, rem = div-1, classInAWeek
	}
	fmt.Println(7*div + within[rem])
}

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func main() {
	scanner.Split(bufio.ScanWords)
	C := scanNum()
	for i := 0; i < C; i++ {
		day, class := scanNum(), []bool{}
		for j := 0; j < 7; j++ {
			num := scanNum()
			class = append(class, num == 1)
		}
		class = append(class, class...)
		solve(class, day)
	}
}
