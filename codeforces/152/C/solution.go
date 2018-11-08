// Looks like `fmt.Scan()` + `scanner` combo would fail when below is there.
// > Package for this problem was not updated by the problem writer or Codeforces administration after we’ve upgraded the judging servers.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, m, s := 0, 0, []string{}
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	raw := strings.Split(scanner.Text(), " ")
	n, _ = strconv.Atoi(raw[0])
	m, _ = strconv.Atoi(raw[1])
	for i := 0; i < n; i++ {
		scanner.Scan()
		s = append(s, scanner.Text())
	}
	r := int64(1)
	for i := 0; i < m; i++ {
		byteMap := map[byte]bool{}
		for j := 0; j < n; j++ {
			byteMap[s[j][i]] = true
		}
		r = r * int64(len(byteMap)) % int64(1000000007)
	}
	fmt.Println(r)
}
