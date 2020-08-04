package main

import (
	"fmt"
	"os"
)

func derange(n int) int {
	if n == 0 {
		return 1
	} else if n == 1 {
		return 0
	} else if n%2 == 1 {
		return n*derange(n-1) - 1
	}
	return n*derange(n-1) + 1
}

func c(n, k int) int {
	a, b := 1, 1
	for ; n > k; n-- {
		a *= n
		b *= n - k
	}
	return a / b
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int
	fmt.Fscan(f, &n, &k)
	fmt.Fprint(q, c(n, k)*derange(n-k))
}
