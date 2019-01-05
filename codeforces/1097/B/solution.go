package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanInt := func() int {
		scanner.Scan()
		num, err := strconv.Atoi(scanner.Text())
		if err != nil {
			log.Fatal(err)
		}
		return num
	}

	n := scanInt()
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = scanInt()
	}

	solutionCount := uint(math.Pow(2.0, float64(n)))
	for i := uint(0); i < solutionCount; i++ {
		sum := 0
		for j := 0; j < n; j++ {
			if (i>>uint(j))&1 == 1 {
				sum += a[j]
			} else {
				sum -= a[j]
			}
		}
		if sum%360 == 0 {
			fmt.Println("YES")
			os.Exit(0)
		}
	}

	fmt.Println("NO")
}
