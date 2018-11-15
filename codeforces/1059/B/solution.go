package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sharp = "#"[0]

// Start from the top-left point, the only point that we can not paint is [1, 1]
var penDirs = [8][2]int{
	[2]int{0, 0},
	[2]int{0, 1},
	[2]int{0, 2},
	[2]int{1, 0},
	[2]int{1, 2},
	[2]int{2, 0},
	[2]int{2, 1},
	[2]int{2, 2},
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	ws := strings.Split(scanner.Text(), " ")
	r, _ := strconv.Atoi(ws[0])
	c, _ := strconv.Atoi(ws[1])
	p := make([][]int, r)
	for i := 0; i < r; i++ {
		scanner.Scan()
		l := scanner.Text()
		p[i] = make([]int, c)
		for j := 0; j < len(l); j++ {
			if l[j] == sharp {
				p[i][j] = 1
			}
		}
	}

	for i := 0; i < (r - 2); i++ {
		for j := 0; j < (c - 2); j++ {
			usePen := true
			for _, v := range penDirs {
				if p[i+v[0]][j+v[1]] == 0 {
					usePen = false
				}
			}
			if !usePen {
				continue
			}
			for _, v := range penDirs {
				p[i+v[0]][j+v[1]] = 2
			}
		}
	}

	for i := 0; i < r; i++ {
		for j := 0; j < c; j++ {
			if p[i][j] == 1 {
				fmt.Println("NO")
				os.Exit(0)
			}
		}
	}
	fmt.Println("YES")
}
