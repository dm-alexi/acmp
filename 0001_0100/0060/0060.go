package main

import (
	"fmt"
	"math"
	"os"
)

func prime(n int) bool {
	if n == 2 {
		return true
	} else if n == 1 || n%2 == 0 {
		return false
	}
	for i, s := 3, int(math.Sqrt(float64(n))); i <= s; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, m int
	fmt.Fscan(f, &n)
	i := 3
	for k := 1; ; i += 2 {
		if prime(i) {
			k++
			if prime(k) {
				m++
				if m == n {
					break
				}
			}
		}
	}
	fmt.Fprint(q, i)
}
