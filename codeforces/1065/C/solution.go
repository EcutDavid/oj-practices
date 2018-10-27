package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func merge(left, right []int) []int {
	size, i, j := len(left)+len(right), 0, 0
	slice := make([]int, size, size)

	for k := 0; k < size; k++ {
		if i > len(left)-1 && j <= len(right)-1 {
			slice[k] = right[j]
			j++
		} else if j > len(right)-1 && i <= len(left)-1 {
			slice[k] = left[i]
			i++
		} else if left[i] < right[j] {
			slice[k] = left[i]
			i++
		} else {
			slice[k] = right[j]
			j++
		}
	}
	return slice
}

func mergeSort(slice []int) []int {
	if len(slice) < 2 {
		return slice
	}
	mid := (len(slice)) / 2
	return merge(mergeSort(slice[:mid]), mergeSort(slice[mid:]))
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	cubes := make([]int, n)
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		scanner.Scan()
		cubes[i], _ = strconv.Atoi(scanner.Text())
	}
	cubes = mergeSort(cubes)

	// Map height to the count of cubes layered in that height
	countMap := map[int]int{}
	index := 0
	height := cubes[0] + 1
	for {
		// Different position might have same height
		for index < len(cubes) && cubes[index] < height {
			index++
		}
		if index == len(cubes) {
			break
		}
		countMap[height] = len(cubes) - index
		height++
	}
	height--

	opCount := 0
	for {
		if height <= cubes[0] {
			break
		}
		count := 0
		for {
			// No more slice operation needed
			if height == cubes[0] {
				break
			}
			count += countMap[height]
			if count > k {
				break
			}
			height--
		}
		opCount++
	}
	fmt.Println(opCount)
}
