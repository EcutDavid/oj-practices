// Key observations:
// 1. For validate whether some moves can reach a goal, can simply check two things:
// 		1. Is the move count long enough?
//		2. If ^ met, we cannot reach the goal if the goal's (dX + dY) % 2 != (moveLength % 2)
// 2. Can validate the answer with binary serach, to save time.
package main

import (
	"fmt"
	"os"
)

var dirMap = map[rune][2]int{
	'R': [2]int{1, 0},
	'L': [2]int{-1, 0},
	'U': [2]int{0, 1},
	'D': [2]int{0, -1},
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func checkValidation(length int, goal [2]int) bool {
	minLength := abs(goal[0]) + abs(goal[1])
	if minLength > length {
		return false
	}
	return (minLength % 2) == (length % 2)
}

func main() {
	n, s, x, y := 0, "", 0, 0
	fmt.Scan(&n, &s, &x, &y)
	if !checkValidation(n, [2]int{x, y}) {
		fmt.Println(-1)
		os.Exit(0)
	}
	sum := make([][2]int, n+1)
	for k, m := range s {
		dir := dirMap[m]
		sum[k+1] = [2]int{sum[k][0] + dir[0], sum[k][1] + dir[1]}
	}
	dX, dY := x-sum[n][0], y-sum[n][1]
	if dX == 0 && dY == 0 {
		fmt.Println(0)
		os.Exit(0)
	}

	l, r, length := 1, n, -1
	for l <= r {
		mid, works := (l+r)/2, false
		for i := 0; i <= (n - mid); i++ {
			sumX, sumY := sum[i+mid][0]-sum[i][0], sum[i+mid][1]-sum[i][1]
			newGoal := [2]int{sumX + dX, sumY + dY}
			if checkValidation(mid, newGoal) {
				works = true
				break
			}
		}
		if works {
			r, length = mid-1, mid
		} else {
			l = mid + 1
		}
	}
	fmt.Println(length)
}
