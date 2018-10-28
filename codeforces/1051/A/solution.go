package main

import (
	"fmt"
)

type char struct {
	cond   func(b byte) bool
	symbol string
	points []int
}

func sortChars(src []*char) {
	for i := 1; i < len(src); i++ {
		for j := i; j > 0; j-- {
			if len(src[j].points) > len(src[j-1].points) {
				src[j], src[j-1] = src[j-1], src[j]
			}
		}
	}
}

func main() {
	var T int
	fmt.Scan(&T)

	for T > 0 {
		T--
		upper := char{
			symbol: "A",
			cond:   func(b byte) bool { return (b >= "A"[0]) && (b <= "Z"[0]) },
		}
		num := char{
			symbol: "0",
			cond:   func(b byte) bool { return (b >= "0"[0]) && (b <= "9"[0]) },
		}
		lower := char{
			symbol: "a",
			cond:   func(b byte) bool { return (b >= "a"[0]) && (b <= "z"[0]) },
		}
		chars := []*char{&upper, &lower, &num}

		var pass string
		fmt.Scan(&pass)
		for i := 0; i < len(pass); i++ {
			for _, c := range chars {
				if c.cond(pass[i]) {
					c.points = append(c.points, i)
				}
			}
		}
		sortChars(chars)

		// Good shape
		if len(chars[2].points) > 0 {
			fmt.Println(pass)
			continue
		}
		// Shape like "AAAAAAA"
		if len(chars[1].points) == 0 {
			newPass := pass[0:chars[0].points[0]] + chars[1].symbol +
				pass[chars[0].points[0]+1:chars[0].points[1]] + chars[2].symbol +
				pass[chars[0].points[1]+1:]
			fmt.Println(newPass)
			continue
		}
		// Shpae like "AAAAaaaa"
		fmt.Println(pass[0:chars[0].points[0]] + chars[2].symbol + pass[chars[0].points[0]+1:])
	}
}
