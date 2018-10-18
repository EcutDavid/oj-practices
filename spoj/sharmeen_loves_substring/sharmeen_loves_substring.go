// Hmm, kinda like an #ad-hoc problem https://www.spoj.com/problems/MOZESLS/
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	s := readLine()
	sMap := map[int]bool{}
	mCount := make([]int, 1, 1e5+1)
	for i := 0; i < len(s); i++ {
		mCount = append(mCount, mCount[i])
		if s[i:i+1] == "s" {
			sMap[i+1] = true
		} else if s[i:i+1] == "m" {
			mCount[i+1]++
		}
	}

	Q, _ := strconv.Atoi(readLine())
	for i := 0; i < Q; i++ {
		raw := strings.Split(readLine(), " ")
		L, _ := strconv.Atoi(raw[0])
		R, _ := strconv.Atoi(raw[1])

		choiceCount := int64(0)
		for j := L; j <= R; j++ {
			// j is 1-indexed, need transform it to 0-indexed when access string
			if s[j-1:j] != "s" {
				continue
			}
			// k is also 1-indexed
			for k := range sMap {
				if (k < L) || (k >= j) {
					continue
				}
				// mCount[j], mCount[j - 1] would be the same
				choiceCount += int64(mCount[j] - mCount[k])
			}
		}

		fmt.Println(choiceCount)
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
