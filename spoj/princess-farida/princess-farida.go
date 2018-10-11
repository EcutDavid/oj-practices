// A basic #dynamic-programming problem.
// https://www.spoj.com/problems/FARIDA/
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solve(coinList []int64) int64 {
	// [n][0] represents the best result assuming the coin is taken from monster n.
	// [n][1] represents the opposite assumption.
	memTable := make([][2]int64, len(coinList)+1)

	memTable[0] = [2]int64{0, 0}
	for i, val := range coinList {
		memTable[i+1][0] = memTable[i][1] + val
		memTable[i+1][1] = memTable[i][0]
		if memTable[i][0] < memTable[i][1] {
			memTable[i+1][1] = memTable[i][1]
		}
	}

	if memTable[len(coinList)][0] > memTable[len(coinList)][1] {
		return memTable[len(coinList)][0]
	}
	return memTable[len(coinList)][1]
}

func main() {
	caseCount, _ := strconv.Atoi(readLine())

	for i := 0; i < caseCount; i++ {
		readLine()
		coins := strings.Split(readLine(), " ")
		coinValList := make([]int64, len(coins))
		for j, coin := range coins {
			val, _ := strconv.Atoi(coin)
			coinValList[j] = int64(val)
		}
		res := solve(coinValList)
		fmt.Printf("Case %v: %v\n", i+1, res)
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
