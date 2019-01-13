package main

import "fmt"

var dotASC = "."[0]

func main() {
	l, w, cs := 0, 0, "byte(0)"
	fmt.Scan(&l, &w, &cs)
	c := cs[0]
	o := make([]string, l)
	for i := 0; i < l; i++ {
		str := ""
		fmt.Scan(&str)
		o[i] = str
	}

	px, py := -1, -1
	for i := 0; i < l; i++ {
		for j := 0; j < w; j++ {
			if o[i][j] == c {
				py, px = i, j
				break
			}
		}
		if (px != -1) || (py != -1) {
			break
		}
	}

	pw, ph := 1, 1
	for i := px + 1; i < w; i++ {
		if o[py][i] == c {
			pw = i - px + 1
		}
	}

	for i := py + 1; i < l; i++ {
		if o[i][px] == c {
			ph = i - py + 1
		}
	}

	ex, ey, ansMap := px+pw-1, py+ph-1, map[byte]bool{}
	if px >= 1 {
		for i := py; i <= ey; i++ {
			ansMap[o[i][px-1]] = true
		}
	}
	if py >= 1 {
		for i := px; i <= ex; i++ {
			ansMap[o[py-1][i]] = true
		}
	}

	if ex < w-1 {
		for i := py; i <= ey; i++ {
			ansMap[o[i][ex+1]] = true
		}
	}
	if ey < l-1 {
		for i := px; i <= ex; i++ {
			ansMap[o[ey+1][i]] = true
		}
	}

	if ansMap[dotASC] {
		fmt.Println(len(ansMap) - 1)
	} else {
		fmt.Println(len(ansMap))
	}
}
