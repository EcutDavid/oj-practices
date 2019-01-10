// "Construct" the tree with two hash tables: parent & children.
// For every even node, its Sv can be evaluated via min value of all the child's value.
package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
	"strconv"
)

func min(nums ...int) int {
	res := math.MaxInt32
	for _, num := range nums {
		if num < res {
			res = num
		}
	}
	return res
}

func visit(node int, children map[int][]int, callback func(int)) {
	callback(node)
	if children[node] == nil {
		return
	}
	for _, v := range children[node] {
		visit(v, children, callback)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanInt := func() int {
		scanner.Scan()
		num, err := strconv.Atoi(scanner.Text())
		if err != nil {
			log.Fatal(err)
		}
		return num
	}

	n := scanInt()
	e, s := make([]int, n-1), make([]int, n+1)
	for i := 0; i < n-1; i++ {
		e[i] = scanInt()
	}
	for i := 0; i < n; i++ {
		s[i+1] = scanInt()
	}

	parent, children := map[int]int{}, map[int][]int{}
	for k, p := range e {
		parent[k+2] = p
		if children[p] == nil {
			children[p] = []int{}
		}
		children[p] = append(children[p], k+2)
	}

	visit(1, children, func(node int) {
		if s[node] != -1 {
			return
		}
		if children[node] == nil {
			s[node] = s[parent[node]]
			return
		}
		childrenS := []int{}
		for _, v := range children[node] {
			childrenS = append(childrenS, s[v])
		}
		s[node] = min(childrenS...)
		if s[node] < s[parent[node]] {
			fmt.Println(-1)
			os.Exit(0)
		}
	})

	sum := int64(0)
	visit(1, children, func(node int) {
		if parent[node] == 0 {
			sum += int64(s[node])
		} else {
			sum += int64(s[node] - s[parent[node]])
		}
	})
	fmt.Println(sum)
}
