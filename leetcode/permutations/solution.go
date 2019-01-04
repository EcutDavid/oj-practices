package solution

// permute accepts a collection of distinct integers, return all possible permutations.
func permute(nums []int) [][]int {
	p := [][]int{}
	for _, d := range nums {
		p = append(p, []int{d})
	}

	for i := 1; i < len(nums); i++ {
		newP := [][]int{}

		for _, d := range p {
			exist := map[int]bool{}
			for _, v := range d {
				exist[v] = true
			}
			for _, v := range nums {
				if exist[v] {
					continue
				}
				newD := make([]int, len(d))
				copy(newD, d)
				newD = append(newD, v)
				newP = append(newP, newD)
			}
		}

		p = newP
	}

	return p
}
