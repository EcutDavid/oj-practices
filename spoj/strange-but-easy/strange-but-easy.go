// A basic #math problem
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func isPrime(num int) bool {
	sqrt := int(math.Floor(math.Sqrt(float64(num))))
	for i := 2; i <= sqrt; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	N, _ := strconv.Atoi(readLine())
	primes := make([]int, 0, 30000)
	primes = append(primes, 2)

	for i := 0; i < N; i++ {
		n, _ := strconv.Atoi(readLine())
		for j := len(primes); j < 3*n; j++ {
			k := primes[len(primes)-1]
			for {
				k++
				if isPrime(k) {
					primes = append(primes, k)
					break
				}
			}
		}
		res := []string{}
		for j := 0; j < n; j++ {
			value := int64(primes[3*j])*int64(primes[3*j+1]) + int64(primes[3*j+2])
			res = append(res, strconv.FormatInt(value, 10))
		}
		fmt.Println(strings.Join(res, " "))
	}
}

var scanner = bufio.NewScanner(os.Stdin)

func readLine() string {
	scanner.Scan()
	return scanner.Text()
}
