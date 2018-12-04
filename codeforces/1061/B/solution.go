package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanNum() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func min(a, b int) int64 {
	if a < b {
		return int64(a)
	}
	return int64(b)
}

func getD(num, d int) int {
	div := int(math.Pow10(d))
	return num / div % 10
}

func countSort(src []int, d int) []int {
	dst, c := make([]int, len(src)), make([]int, 10)
	for _, v := range src {
		c[getD(v, d)]++
	}
	for i := 1; i < 10; i++ {
		c[i] += c[i-1]
	}
	for i := len(src) - 1; i >= 0; i-- {
		digit := getD(src[i], d)
		index := c[digit] - 1
		dst[index], c[digit] = src[i], c[digit]-1
	}
	return dst
}

// Using radixSort won't make this case running faster in judge system... Hmm...
func radixSort(src []int) []int {
	for i := 0; i < 10; i++ {
		src = countSort(src, i)
	}
	return src
}

func main() {
	scanner.Split(bufio.ScanWords)
	n, _ := scanNum(), scanNum()
	b := make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = scanNum()
	}
	sort.Ints(b)

	max, sum, needHelp := 0, int64(0), 0
	for i := 0; i < n; {
		len, extra, newSum, oldMax := 1, int64(0), int64(0), max
		for j := i + 1; j < n; j++ {
			if b[i] == b[j] {
				len++
			} else {
				break
			}
		}

		newSum, max, extra = sum+min(max, b[i]-1), b[i], min(b[i]-max-1, len-1)
		if extra >= 0 && len > 1 {
			newSum += min(max, b[i]-1)*int64(len-1) + extra
		}
		i += len

		if (max - oldMax) > len {
			needHelp += max - oldMax - 1
		} else if needHelp > 0 {
			contribution := int(min(len-(max-oldMax), needHelp))
			needHelp, newSum = needHelp-contribution, newSum+int64(contribution)
		}
		sum = newSum
	}
	fmt.Println(sum)
}
