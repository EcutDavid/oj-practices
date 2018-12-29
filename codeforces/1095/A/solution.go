package main

import "fmt"

func main() {
	n, s, cur := 0, "", 0
	fmt.Scan(&n, &s)
	res := []byte{}
	for i := 1; i <= 10; i++ {
		res, cur = append(res, s[cur]), cur+i
		if cur >= n {
			break
		}
	}
	fmt.Println(string(res))
}
