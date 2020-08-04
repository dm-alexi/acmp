package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, m int
	fmt.Fscan(f, &n, &m)
	if m == 0 {
		n = 1
	} else if m > 1 {
		n = n / (m - 1) * (2*n - m + 1 + n/(m-1)*(1-m)) / 2
	}
	fmt.Fprint(q, n)
}
