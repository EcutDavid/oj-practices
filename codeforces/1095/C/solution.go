package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, k uint
	fmt.Scan(&n, &k)

	bitMap := map[uint]uint{}
	for i := 0; i < 32; i++ {
		target := uint(1) << uint(i)
		if (n & target) > 0 {
			bitMap[target]++
		}
	}

	min, max := uint(len(bitMap)), n
	if (k < min) || (k > max) {
		fmt.Println("NO")
		os.Exit(0)
	}

	split := k - min
	for i := 0; i < int(split); i++ {
		for k, v := range bitMap {
			if (k == 1) || (v == 0) {
				continue
			}

			bitMap[k], bitMap[k/2] = v-1, bitMap[k/2]+2
			break
		}
	}

	res := []string{}
	for k, v := range bitMap {
		for i := 0; i < int(v); i++ {
			res = append(res, strconv.Itoa(int(k)))
		}
	}
	fmt.Println("YES")
	fmt.Println(strings.Join(res, " "))
}
