package main

import (
	"fmt"
)

func main() {
	w, str, prev, dCount := 0, "", "", 0
	fmt.Scan(&w, &str)

	for i := 0; i < w; i++ {
		cur := str[i : i+1]
		if (prev == "U" && cur == "R") || (prev == "R" && cur == "U") {
			dCount, prev = dCount+1, ""
		} else {
			prev = cur
		}
	}

	fmt.Println(w - dCount)
}
