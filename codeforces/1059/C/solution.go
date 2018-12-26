// Good question! Need to be careful with the safe state transformation.
// When there are "3" left, instead of [1, 1, 2], [1, 1, 3] is much better.
// Otherwise, can reason that, an array can be reduced to only the even left, apply "/ 2" to every number of the array for the coming reduce.
package main

import (
	"bytes"
	"fmt"
	"strconv"
)

func main() {
	n := 0
	fmt.Scan(&n)
	res, level := []int{}, 1

	for n > 0 {
		if n == 3 {
			res = append(res, []int{level, level, level * 3}...)
			break
		}
		reduce := 0
		for i := 1; i <= n; i++ {
			if i%2 == 1 {
				res, reduce = append(res, level), reduce+1
			}
		}
		n, level = n-reduce, level*2
	}

	buffer := []byte{}
	output := bytes.NewBuffer(buffer)
	output.WriteString(strconv.Itoa(res[0]))

	for i := 1; i < len(res); i++ {
		output.WriteString(" " + strconv.Itoa(res[i]))
	}

	fmt.Println(output.String())
}
