// https://code.google.com/codejam/contest/5374486/dashboard
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	c, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < c; i++ {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())
		nums := make([]int, n)
		for j := 0; j < n; j++ {
			scanner.Scan()
			nums[j], _ = strconv.Atoi(scanner.Text())
		}
		sort.Ints(nums)

		numMap := map[int][2]int{}
		for j := 0; j < n; j++ {
			v, ok := numMap[nums[j]]
			if !ok {
				numMap[nums[j]] = [2]int{j, j}
			} else {
				numMap[nums[j]] = [2]int{v[0], v[1] + 1}
			}
		}

		count := int64(0)
		for j := 0; j < (n - 2); j++ {
			maxK := (n - 1)
			if nums[j] == 0 && nums[len(nums)-1] > 0 {
				maxK = n
			}
			for k := j + 1; k < maxK; k++ {
				if nums[j] == 0 {
					if nums[k] == 0 {
						count += int64(numMap[0][1] - k)
					} else {
						count += int64(numMap[0][1] - j)
					}
				} else if nums[j] == 1 {
					count += int64(numMap[nums[k]][1] - k)
				} else {
					z := int64(nums[j]) * int64(nums[k])
					if z > 200000 {
						continue
					}
					v, ok := numMap[int(z)]
					if ok {
						count += int64(v[1] - v[0] + 1)
					}
				}
			}
		}
		fmt.Printf("Case #%d: %d\n", i+1, count)
	}
}
