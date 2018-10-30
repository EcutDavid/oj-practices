package main

import (
	"fmt"
	"os"
)

func main() {
	w, str, choice := 0, "", 0
	fmt.Scan(&w, &str)
	for i := 1; i <= w/2; i++ {
		if str[0:i] == str[i:2*i] {
			choice = i
		}
	}
	if choice == 0 {
		fmt.Println(w)
		os.Exit(0)
	}
	fmt.Println(w - choice + 1)
}
