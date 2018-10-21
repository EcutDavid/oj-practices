// A basic #number-theory #newbie question,
// This question has a strange 700 bytes source code limitation,
// that's why the variable names are so weird(an excuse for didn't spend time improving the code).
// Since, the 700 bytes limitation, we have to delete this 4 lines comments before submitting the solution.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	ps := [9][]int{}
	for i := 1; i <= 9; i++ {
		l := []int{i}
		for {
			j := l[len(l)-1] * i % 10
			if l[0] == j {
				break
			}
			l = append(l, j)
		}
		ps[i-1] = l
	}

	t, _ := ti(rl())
	for i := 0; i < t; i++ {
		ab := strings.Split(rl(), " ")
		a, _ := ti(ab[0])
		a %= 10
		b, _ := ti(ab[1])
		if a == 0 {
			fmt.Println(0)
		} else if b == 0 {
			fmt.Println(1)
		} else {
			b = (b - 1) % len(ps[a-1])
			fmt.Println(ps[a-1][b])
		}
	}
}

var s = bufio.NewScanner(os.Stdin)
var ti = strconv.Atoi

func rl() string {
	s.Scan()
	return s.Text()
}
