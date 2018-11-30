// Seperate the string to groups, for each group,
// there will be a chance to replace a S to G right after that group
package main

import (
	"bufio"
	"fmt"
	"os"
)

var scanner = bufio.NewScanner(os.Stdin)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1000000)
	n, line, groups := 0, "", [][2]int{}
	fmt.Fscanf(reader, "%d\n%s\n", &n, &line)
	l, r := -1, -1
	// Break the input into G groups, each group stands by [lIndex, RIndex]
	for i := 0; i < len(line); i++ {
		if line[i:i+1] == "G" {
			if l != -1 {
				r++
			} else {
				l, r = i, i
			}
			if i == (len(line) - 1) {
				groups = append(groups, [2]int{l, r})
			}
			continue
		}
		if l != -1 {
			groups = append(groups, [2]int{l, r})
		}
		l, r = -1, -1
	}

	max := 0
	for i := 0; i < len(groups); i++ {
		res := groups[i][1] - groups[i][0] + 1
		if i == (len(groups) - 1) {
			if i > 0 {
				res++
			}
		} else {
			res++
			if (groups[i+1][0] - groups[i][1]) == 2 {
				res += groups[i+1][1] - groups[i+1][0] + 1
				if (i == (len(groups) - 2)) && (i == 0) {
					res--
				}
			}
		}

		if max < res {
			max = res
		}
	}

	fmt.Println(max)
}
