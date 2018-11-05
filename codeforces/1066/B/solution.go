package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	scanner.Scan()
	w, _ := strconv.Atoi(scanner.Text())
	arr := []string{}
	for scanner.Scan() {
		arr = append(arr, scanner.Text())
	}

	unHeatIndex, count := 0, 0
	for unHeatIndex < len(arr) {
		l, r, pos := unHeatIndex-w+1, unHeatIndex+w-1, -1
		for i := l; i <= r; i++ {
			if (i >= 0) && (i < len(arr)) && (arr[i] == "1") {
				pos = i
			}
		}
		if pos == -1 {
			fmt.Println(-1)
			os.Exit(0)
		}
		unHeatIndex = pos + w
		count++
	}
	fmt.Println(count)
}
