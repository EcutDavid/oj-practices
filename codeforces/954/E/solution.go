// Huge mistakes I made
// a, b are between 1-1e6, I used int64(a * b) instead of int64(a) * int64(b)
// 													^ and made that mistake three times ^ ......
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type tapType [][2]int

func (t tapType) Len() int           { return len(t) }
func (t tapType) Less(i, j int) bool { return t[i][1] < t[j][1] }
func (t tapType) Swap(i, j int)      { t[i], t[j] = t[j], t[i] }

func main() {
	n, t, scanner, res := 0, 0, bufio.NewScanner(os.Stdin), 0.0
	scanner.Split(bufio.ScanWords)

	fmt.Scan(&n, &t)
	capa, temp := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		capa[i], _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		temp[i], _ = strconv.Atoi(scanner.Text())
		if temp[i] == t {
			res += float64(capa[i])
		}
	}

	var coldPower, coldCapa, hotPower, hotCapa int64 = 0, 0, 0, 0
	hot, cold := make([][2]int, 0, n), make([][2]int, 0, n)
	for i := 0; i < n; i++ {
		if temp[i] < t {
			d := t - temp[i]
			cold = append(cold, [2]int{capa[i], d})
			coldPower += int64(d) * int64(capa[i])
			coldCapa += int64(capa[i])
		}
		if temp[i] > t {
			d := temp[i] - t
			hot = append(hot, [2]int{capa[i], d})
			hotPower += int64(d) * int64(capa[i])
			hotCapa += int64(capa[i])
		}
	}

	target, powerLeft := hot, coldPower
	if hotPower > coldPower {
		res += float64(coldCapa)
	} else {
		target, powerLeft = cold, hotPower
		res += float64(hotCapa)
	}
	sort.Sort(tapType(target))

	for _, v := range target {
		p := int64(v[0]) * int64(v[1])
		if powerLeft < p {
			res += float64(powerLeft) / float64(v[1])
			break
		} else {
			powerLeft -= p
			res += float64(v[0])
		}
	}
	fmt.Printf("%.14f\n", res)
}
