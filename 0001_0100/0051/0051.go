package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s string
	var n int
	fmt.Fscan(f, &n, &s)
	k := len(s)
	for i := n - k; i > 0; i -= k {
		n *= i
	}
	fmt.Fprint(q, n)
}
