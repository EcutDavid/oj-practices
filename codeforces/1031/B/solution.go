// Spent more than 4 hours...... Hmm...
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func genT(a, b []bool) []int {
	n := len(a) + 1
	t := make([]int, n)
	for i := 0; i < n; i++ {
		t[i] = 2
	}

	goodCount, firstGood := 0, -1
	for i := 0; i < n-1; i++ {
		// a[i] == 0 but b[i] == 1 is impossible to happen
		if !a[i] && b[i] {
			return []int{}
		}
		if a[i] && b[i] {
			if t[i] == 0 {
				return []int{}
			}
			if firstGood == -1 {
				firstGood = i
			}
			t[i], t[i+1], goodCount = 1, 1, goodCount+1
		}
		if !a[i] && !b[i] {
			if t[i] == 1 {
				return []int{}
			}
			if firstGood == -1 {
				firstGood = i
			}
			t[i], t[i+1], goodCount = 0, 0, goodCount+1
		}
	}

	// Which means a, b are all all following the pattern of a[i] == 1, b[i] == 0,
	// so there are two possiblities, can choose anyone.
	if goodCount == 0 {
		for i := 0; i < n; i++ {
			t[i] = i % 2
		}
		return t
	}

	// Construct the t, because there is only one way to construct it.
	for i := firstGood - 1; i >= 0; i-- {
		if t[i+1] == 0 {
			t[i] = 1
		} else {
			t[i] = 0
		}
	}
	for i := firstGood + 2; i < n; i++ {
		if t[i] != 2 {
			continue
		}
		if t[i-1] == 0 {
			t[i] = 1
		} else {
			t[i] = 0
		}
	}
	// Validate the newly constructed t.
	for i := 0; i < n-1; i++ {
		if (t[i]|t[i+1] == 1) != a[i] {
			return []int{}
		}
		if (t[i]&t[i+1] == 1) != b[i] {
			return []int{}
		}
	}
	return t
}

func main() {
	var n int
	fmt.Scan(&n)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	a1, a2, b1, b2 := make([]bool, n-1), make([]bool, n-1), make([]bool, n-1), make([]bool, n-1)
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		a1[i] = (num & 1) == 1
		a2[i] = (num & 2) == 2
	}
	for i := 0; i < n-1; i++ {
		scanner.Scan()
		num, _ := strconv.Atoi(scanner.Text())
		b1[i] = (num & 1) == 1
		b2[i] = (num & 2) == 2
	}
	t1, t2 := genT(a1, b1), genT(a2, b2)
	if (len(t1) != n) || (len(t2) != n) {
		fmt.Println("NO")
		os.Exit(0)
	}
	fmt.Println("YES")
	t := make([]string, n)
	for i := 0; i < n; i++ {
		t[i] = strconv.Itoa(t1[i] | (t2[i] << 1))
	}
	fmt.Println(strings.Join(t, " "))
}
