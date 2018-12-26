package main

import "fmt"

func main() {
	w, origin := "", ""
	fmt.Scan(&w)
	for len(w) > 0 {
		if len(w)%2 == 0 {
			origin, w = w[len(w)-1:len(w)]+origin, w[:len(w)-1]
		} else {
			origin, w = w[:1]+origin, w[1:]
		}
	}
	fmt.Println(origin)
}
