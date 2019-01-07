// An interesting #geometry problem!
package main

import "fmt"

func main() {
	angleMap := map[int]int{}
	for i := 3; i <= 360; i++ {
		unit := float64(180) / float64(i)
		for j := 1; j <= (i - 2); j++ {
			angle := unit * float64(j)
			if angle-float64(int(angle)) > .0 {
				continue
			}
			if angleMap[int(angle)] != 0 {
				continue
			}
			angleMap[int(angle)] = i
		}
	}

	n := 0
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		angle := 0
		fmt.Scan(&angle)
		fmt.Println(angleMap[angle])
	}
}
