package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

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

	n, adj := scanInt(), map[int]map[int]bool{}
	for i := 1; i <= n; i++ {
		adj[i] = map[int]bool{}
	}
	for i := 2; i <= n; i++ {
		prev := scanInt()
		adj[prev][i], adj[i][prev] = true, true
	}

	queue, visited, parent, pointer := []int{1}, map[int]bool{1: true}, map[int]int{}, 0
	for pointer < len(queue) {
		task := queue[pointer]
		for k := range adj[task] {
			if visited[k] {
				continue
			}
			visited[k], queue, parent[k] = true, append(queue, k), task
		}
		pointer++
	}

	path, pointer := []int{n}, n
	for parent[pointer] != 0 {
		path, pointer = append(path, parent[pointer]), parent[pointer]
	}

	pathStr := []string{}
	for i := len(path) - 1; i >= 0; i-- {
		pathStr = append(pathStr, strconv.Itoa(path[i]))
	}

	fmt.Println(strings.Join(pathStr, " "))
}
