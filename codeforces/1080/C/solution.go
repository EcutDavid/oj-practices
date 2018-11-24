// If there are intersection, white part should be handle as two seperated parts.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// (1, 1) is white
func calcBlock(x1, y1, x2, y2 int) (int64, int64) {
	width, height := x2-x1+1, y2-y1+1
	w, b := int64(width)*(int64(height)/2), int64(width)*(int64(height)/2)
	if height%2 == 1 {
		w, b = w+int64(width/2), b+int64(width/2)
		if width%2 == 1 {
			if (x2+y2)%2 == 0 {
				w++
			} else {
				b++
			}
		}
	}
	return w, b
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
func min(x, y int) int {
	if x > y {
		return y
	}
	return x
}

func getIntsection(x1, y1, x2, y2, x3, y3, x4, y4 int) (int, int, int, int) {
	// fmt.Println("x1, y1, x2, y2, x3, y3, x4, y4", x1, y1, x2, y2, x3, y3, x4, y4)
	x5, y5 := max(x1, x3), max(y1, y3)
	x6, y6 := min(x2, x4), min(y2, y4)
	// fmt.Println(x5, y5, x6, y6)
	if (x5 > x6) || (y5 > y6) {
		return -1, -1, -1, -1
	}
	return x5, y5, x6, y6
}

func getNum(s *bufio.Scanner) int {
	s.Scan()
	num, _ := strconv.Atoi(s.Text())
	return num
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	t := getNum(scanner)

	for i := 0; i < t; i++ {
		n, m := getNum(scanner), getNum(scanner)
		x1, y1, x2, y2 := getNum(scanner), getNum(scanner), getNum(scanner), getNum(scanner)
		x3, y3, x4, y4 := getNum(scanner), getNum(scanner), getNum(scanner), getNum(scanner)
		// fmt.Println("case", x1, y1, x2, y2, x3, y3, x4, y4)
		x5, y5, x6, y6 := getIntsection(x1, y1, x2, y2, x3, y3, x4, y4)
		hasIntsection := x5 != -1

		tw, tb := calcBlock(1, 1, m, n)
		// b1 gonna become w
		_, b1 := calcBlock(x1, y1, x2, y2)
		tw, tb = tw+b1, tb-b1
		if hasIntsection {
			// intb gonna "become" b
			_, intb := calcBlock(x5, y5, x6, y6)
			tw, tb = tw-intb, tb+intb
		}
		// w2 gonna become b
		w2, _ := calcBlock(x3, y3, x4, y4)
		tw, tb = tw-w2, tb+w2

		fmt.Println(tw, tb)
	}
}
