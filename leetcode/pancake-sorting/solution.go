// We need progressively make the last elements "good"
package main

func reverse(a []int) []int {
	b := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		b[i] = a[len(a)-i-1]
	}
	return b
}

func flip(a []int, k int) []int {
	return append(reverse(a[:k+1]), a[k+1:]...)
}

func pancakeSort(A []int) []int {
	flips := []int{}
	for i := len(A) - 1; i >= 0; i-- {
		if A[i] == i+1 {
			continue
		}
		k := -1
		for index, v := range A {
			if v == i+1 {
				k = index
				break
			}
		}
		// Flip the target to head, then, flip it to the target position
		if k != 0 {
			A, flips = flip(A, k), append(flips, k+1)
		}
		A, flips = flip(A, i), append(flips, i+1)
	}
	return flips
}

func main() {
}
